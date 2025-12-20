# RF Firmware

These Nuphy keyboards have 3 firmware components:

- The main keyboard firmware, QMK.  This repo contains the source code for that.
- The RF chip firmware.  This is proprietary and only available in binary form.  It is included here.  Requires Android or iOS to update.
- The 2.4GHz dongle firmware.  This is proprietary too, and requires Windows or MacOS to update.  The dongle firmware version should match the RF chip firmware version.

The RF firmware is shared to NuPhy users on their web site, via e-mail to customers, and sometimes on their official Discord by users.
It is the firmware that controls the `NRF52810` chipset that does the Bluetooth and 2.4GHz dongle transmissions. It also handles synchronization of data such as battery level.

My (ToyKeeper's) firmware is tested on `v2.1.5`, which I personally use.  Consider updating the RF firmware if you have wireless issues.

It is important to also update the dongle firmware with a matching version.  The tool for this runs on Windows or MacOS, with filenames like `dongle_52820_upgrade_v2.1.5.exe` .  I didn't have any luck updating the dongle using a Windows 10 virtual machine in virt-manager, so I briefly borrowed a friend's Macbook to update it via MacOS.  YMMV.

The same files should be available from Nuphy's site:  [https://nuphy.com/pages/qmk-firmwares#firmwaredetails12](https://nuphy.com/pages/qmk-firmwares#firmwaredetails12)

# Flashing

Refer to the [Flashing Instructions](Instructions_on_Flashing_the_RF_Firmwares.docx) for updating the RF module. You can also put the module into `DFU` mode by mapping the `RF DFU` key in VIA.

# Compatibility

The RF firmware is compatible on Air75 V2, Air60 V2 and Air96 V2 since all 3 boards use the same hardware.

# Improvements

Users have reported potential improvements on wireless range and connectivity by updating to the latest firmware. Consider updating if you face issues with wireless connectivity but please see the disclaimer section as well.

# Disclaimer

These firmware are closed source provided by NuPhy. I do not have changelogs and do not know what the difference between the versions are. Supposedly, per NuPhy staff, each iteration is supposed to improve upon the RF performance and stability but no empirical evidence from my end supports that (since I don't have major issues overall).

As I do not have the version that shipped with the board you **cannot** go back to the original firmware if anything goes wrong (but it shouldn't). You can, however, flash to another RF firmware version.

Consider this a case of `if it ain't broke, don't fix it` scenario if the stock firmware works for you.
