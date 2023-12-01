CLI version: 0.1.0
Profile generator API: 68.8.1
Libiio version: 0.25-b6028fd

Usage:
	adrv9002-iio-cli --config [arg] --uri [arg] --device [arg]
		Generate profile and stream from the specified config file and write it to the iio device.
		(Only available if build with libiio)

	adrv9002-iio-cli --config [arg] --stream [arg]
		Generate stream from the specified config save it to a file.

	adrv9002-iio-cli --config [arg] --profile [arg]
		Generate profile from the specified config save it to a file.

Options:
	-h, --help
		Show help.

	-v, --version
		Show software versions.

	-c, --config [arg]
		Specify config file containing a adrv9002_config structure in libini format.

	-i, --uri [arg]
		Set the iio device's uri.
		eg: 'ip:192.168.2.1'
		(Only available if build with libiio)

	-d, --device [arg]
		Set the name of the device you will write the stream and profile to.
		eg: 'adrv9002-phy'
		(Only available if build with libiio)

	-s, --stream [arg]
		Specify the file which the generated stream will be written on.

	-p, --profile [arg]
		Specify the file which the generated profile will be written on.

