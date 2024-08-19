# RGB Control

## Overview

RGB Control is a simple C++ desktop application built using Qt that allows users to control RGB lighting through an arduino. The application communicates with an Arduino board to manage the RGB lighting based on user input. It is designed to work on both Windows and Linux platforms.

## Features

- **Cross-Platform**: Available for both Windows and Linux.
- **RGB Control**: Sends signals to an Arduino to project corresponding RGB colors.
- **User Interface**: Simple and intuitive interface to control various RGB colors.

## Installation

### Windows Installation

1. **Download the Installer**:
   - You can download the Windows installer from the [releases](link-to-your-release) page.

2. **Run the Installer**:
   - Double-click the downloaded `.exe` file and follow the installation wizard.

3. **Run the Application**:
   - After installation, you can find the application in the Start Menu or on your Desktop.

### Linux Installation

1. **Build the Binary**:
   ```bash
    mkdir build
    cmake ..
    make -j
     ```

2. **Make the Binary Executable**:
   - Open a terminal and navigate to the directory where you downloaded the binary.
   - Run the following command to make the binary executable:
     ```bash
     chmod +x RGBControl
     ```

3. **Run the Application**:
   - You can now run the application by executing:
     ```bash
     ./RGBControl
     ```

**Note:** If you're not able to detect the arduinos serial port, make sure to **disable brltty**.
```bash
systemctl stop brltty-udev.service
sudo systemctl mask brltty-udev.service
systemctl stop brltty.service
systemctl disable brltty.service
```

## Usage

1. **Connect Your Arduino**:
   - Ensure your Arduino board is connected to your computer and is set up to receive RGB control signals.

2. **Select the Serial Port**:
   - Open the application and select the appropriate serial port from the dropdown menu.

3. **Connect to the Arduino**:
   - Click the "Connect" button to establish a connection with the Arduino board.

4. **Control RGB Lighting**:
   - Use the provided buttons to send RGB color commands to the Arduino. The Arduino will project the corresponding RGB colors.

## Development

### Prerequisites

- **Qt**: You need the Qt framework to build and run the application.
- **Arduino**: Ensure you have the necessary Arduino setup to receive and handle RGB control signals.

### Building from Source

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/RGBControl.git
   cd RGBControl
