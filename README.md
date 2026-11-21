# RPDT Class Home Alarm System

An Arduino Uno door alarm for Wokwi in VS Code. A slide switch represents the door. The green LED shows that the alarm is armed. Opening the door lights the red LED and sounds the buzzer.

## Run the simulation

1. Download `RPDT Class Home Alarm System.zip` from this repository and extract it.
2. Open the extracted **RPDT Class Home Alarm System** folder in VS Code.
3. Install the **Wokwi Simulator** extension. If prompted for a license, run **Wokwi: Request a New License** from the Command Palette and follow the activation steps.
4. Run **Wokwi: Start Simulator** from the Command Palette. The ZIP includes the compiled firmware. After changing the code, install **PlatformIO IDE** and run **PlatformIO: Build** before restarting the simulator.

## Try the alarm

1. Start with the door switch closed. The green LED lights up.
2. Flip the door switch. The red LED lights up and the buzzer sounds.
3. Close the door. The alarm stays on.
4. Press the blue **Reset** button. The buzzer stops and the green LED lights up again. Reset works only with the door closed.

The circuit is in `diagram.json`, the Arduino source is in `src/main.cpp`, and `wokwi.toml` points to the built firmware.
