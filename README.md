# RPDT Class Home Alarm System

An Arduino Uno door alarm for Wokwi in VS Code. A slide switch represents the door. The green LED shows that the alarm is armed. Opening the door lights the red LED and sounds the buzzer.

## Download

**[Download the complete project ZIP](https://github.com/srsumeru/rpdt-class-home-alarm-system/raw/refs/heads/main/RPDT%20Class%20Home%20Alarm%20System.zip)**

The ZIP includes the Arduino source, Wokwi circuit, PlatformIO configuration, existing compiled firmware, this guide, and the MIT license. A GitHub account is not required.

1. Click **Download the complete project ZIP** above.
2. Right-click the ZIP and choose **Extract All**.
3. In VS Code select **File > Open Folder** and choose the extracted `rpdt-class-home-alarm-system` folder containing `platformio.ini` and `wokwi.toml`.
4. Follow **Run the simulation** below.

Alternatively, choose the green **Code > Download ZIP** button to download the latest repository snapshot. Open the extracted folder containing `platformio.ini`; that snapshot also contains a separate copy of the project ZIP.

## Run the simulation in VS Code

1. Install the **Wokwi Simulator** extension (`wokwi.wokwi-vscode`).
2. If activation is required, open the Command Palette with **Ctrl+Shift+P**, run **Wokwi: Request a New License**, and follow Wokwi's browser activation steps. Wokwi's own account and license terms apply separately from this project's MIT license.
3. Open the Command Palette and run **Wokwi: Start Simulator**.
4. The package includes the original `.pio/build/uno/firmware.hex` and `firmware.elf`, so an initial simulation can use those files.

After editing `src/main.cpp`, install **PlatformIO IDE** (`platformio.platformio-ide`), allow its Arduino/AVR tools to install, run **PlatformIO: Build**, and restart the simulator. Internet access is needed for extension/tool installation and activation. Wokwi loads compiled firmware; it does not compile edits itself.

If you use the PlatformIO command-line tools, build from the project folder with:

```sh
pio run -e uno
```

Official help: [Wokwi installation and activation](https://docs.wokwi.com/vscode/getting-started) and [Wokwi project configuration](https://docs.wokwi.com/vscode/project-config).

This is an Arduino/PlatformIO project. Run it in VS Code with Wokwi or upload it to an Arduino Uno; it does not use Spring Boot.

## Try the alarm

1. Start with the door switch closed. The green LED lights up.
2. Flip the door switch. The red LED lights up and the buzzer sounds.
3. Close the door. The alarm stays on.
4. Press the blue **Reset** button. The buzzer stops and the green LED lights up again. Reset works only with the door closed.

## Arduino Uno pins

| Component | Uno pin | Connection |
| --- | --- | --- |
| Door switch | D2 | Centre terminal to D2; one side to GND. The input uses INPUT_PULLUP. |
| Reset button | D3 | Button between D3 and GND; the input uses INPUT_PULLUP. |
| Buzzer | D8 | Positive to D8, negative to GND. |
| Red alarm LED | D9 | D9 through a 220-ohm resistor to the LED anode; cathode to GND. |
| Green armed LED | D10 | D10 through a 220-ohm resistor to the LED anode; cathode to GND. |

The complete simulated wiring is in [diagram.json](diagram.json).

## Source files

| File | Purpose |
| --- | --- |
| [src/main.cpp](src/main.cpp) | Arduino alarm logic |
| [diagram.json](diagram.json) | Wokwi circuit |
| [platformio.ini](platformio.ini) | Arduino Uno build configuration |
| [wokwi.toml](wokwi.toml) | Paths to the compiled firmware |
| [.vscode/extensions.json](.vscode/extensions.json) | Recommended VS Code extensions |
| [LICENSE](LICENSE) | MIT open-source license |

The existing compiled firmware is included for convenience. Rebuild after changing the source.

## Open-source license

The original project source and documentation are available under the **[MIT License](LICENSE)**. You may use, modify, and redistribute them, including commercially, while retaining the copyright and license notice. Arduino and other third-party components retain their own licenses.

## Troubleshooting

- **Firmware not found:** open the folder containing `wokwi.toml`, confirm the `.pio/build/uno` firmware files were extracted, or run **PlatformIO: Build**.
- **Edits do not appear:** rebuild the firmware and restart Wokwi.
- **Alarm will not reset:** close the door switch before pressing the blue Reset button.
- **License prompt:** complete Wokwi's activation steps linked above.
