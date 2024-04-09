import adrv9002
import pprint
import copy

# Create profile configuration
rx1 = adrv9002.rx_radio_channel_config()
rx1.enabled = True
rx1.adc_high_performance_mode = True
rx1.frequency_offset_correction_enable = False
rx1.analog_filter_power_mode = 2  # High power/performance
rx1.analog_filter_biquad = False
rx1.analog_filter_bandwidth_hz = 18000000
rx1.channel_bandwidth_hz = 18000000
rx1.sample_rate_hz = 30720000
rx1.nco_enable = False
rx1.nco_frequency_hz = 0
rx1.rf_port = 0  # RX-A

rx2 = copy.deepcopy(rx1)

tx1 = adrv9002.tx_radio_channel_config()
tx1.enabled = True
tx1.sample_rate_hz = 30720000
tx1.frequency_offset_correction_enable = False
tx1.analog_filter_power_mode = 2  # High power/performance
tx1.channel_bandwidth_hz = 18000000
tx1.orx_enabled = True
tx1.elb_type = 2

tx2 = copy.deepcopy(tx1)

r_cfg = adrv9002.radio_config()
r_cfg.adc_rate_mode = 3  # High Performance
r_cfg.fdd = False
r_cfg.lvds = True
r_cfg.ssi_lanes = 2
r_cfg.ddr = True
r_cfg.adc_rate_mode = 3  # High Performance
r_cfg.short_strobe = True
r_cfg.rx_config[0] = rx1
r_cfg.rx_config[1] = rx2
r_cfg.tx_config[0] = tx1
r_cfg.tx_config[1] = tx2

clk_cfg = adrv9002.clock_config()
clk_cfg.device_clock_frequency_khz = 38400
clk_cfg.clock_pll_high_performance_enable = True
clk_cfg.clock_pll_power_mode = 2  # High power/performance
clk_cfg.processor_clock_divider = 1

adrv_cfg = adrv9002.adrv9002_config()
adrv_cfg.clk_cfg = clk_cfg
adrv_cfg.radio_cfg = r_cfg

# Generate profile and stream binary
profile, stream = adrv9002.generate_profile(adrv_cfg)

pprint.pprint(profile)
