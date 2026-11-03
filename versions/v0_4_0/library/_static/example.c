#include <adrv9002_iio.h>
#include <stdio.h>
#include <stdlib.h>

// Same as ref_profile.json
adrv9002_config lte_lvs_3072_MHz_10() {
  rx_radio_channel_config rx1;
  rx1.enabled = 1;
  rx1.adc_high_performance_mode = true;
  rx1.frequency_offset_correction_enable = false;
  rx1.analog_filter_power_mode = 2; // High power/performance
  rx1.analog_filter_biquad = false;
  rx1.channel_bandwidth_hz = 18000000;
  rx1.sample_rate_hz = 30720000;
  rx1.nco_enable = false;
  rx1.nco_frequency_hz = 0;
  rx1.rf_port = 0; // RX-A

  // Copy rx1 to rx2
  rx_radio_channel_config rx2 = rx1;
  rx2.rf_port = 0; // RX-B

  // TX side
  tx_radio_channel_config tx1;
  tx1.enabled = 1;
  tx1.sample_rate_hz = 30720000;
  tx1.frequency_offset_correction_enable = false;
  tx1.analog_filter_power_mode = 2; // High power/performance
  tx1.channel_bandwidth_hz = 18000000;
  tx1.orx_enabled = true;
  tx1.elb_type = 2;

  // Copy tx1 to tx2
  tx_radio_channel_config tx2 = tx1;

  radio_config r_cfg;
  r_cfg.adc_rate_mode = 3; // High Performance
  r_cfg.fdd = false;
  r_cfg.lvds = true;
  r_cfg.ssi_lanes = 2;
  r_cfg.ddr = true;
  r_cfg.adc_rate_mode = 3; // High Performance
  r_cfg.short_strobe = true;
  r_cfg.rx_config[0] = rx1;
  r_cfg.rx_config[1] = rx2;
  r_cfg.tx_config[0] = tx1;
  r_cfg.tx_config[1] = tx2;

  clock_config clk_cfg;
  clk_cfg.device_clock_frequency_khz = 38400;
  clk_cfg.clock_pll_high_performance_enable = true;
  clk_cfg.clock_pll_power_mode = 2; // High power/performance
  clk_cfg.processor_clock_divider = 1;

  adrv9002_config adrv_cfg;
  adrv_cfg.clk_cfg = clk_cfg;
  adrv_cfg.radio_cfg = r_cfg;

  return adrv_cfg;
}

int main() {

  // Create configuration
  adrv9002_config adrv_cfg = lte_lvs_3072_MHz_10();

  // Generate profile and stream image
  char *profile;
  char *stream_image;
  size_t profile_size;
  size_t stream_image_size;

  int ret = adrv9002_generate_profile(&adrv_cfg, &profile, &profile_size,
                                      &stream_image, &stream_image_size);

  if (ret != 0) {
    printf("Error generating profile: %d\n", ret);
    return ret;
  }

  // Write stream and profile to files
  FILE *fp;
  fp = fopen("profile.json", "w");
  fwrite(profile, 1, profile_size, fp);
  fclose(fp);
  fp = fopen("stream_image.bin", "w");
  fwrite(stream_image, 1, stream_image_size, fp);
  fclose(fp);
}