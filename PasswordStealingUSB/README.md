# Arduino Micro BadUSB Device

This repository contains the code and instructions for creating a BadUSB device using an Arduino Micro. This device is designed to automatically run the WebBrowserPassView software to extract saved passwords from web browsers and save them for analysis. 

## Quick Links

- [Home Page](https://leumas.tech)
- [Contact Page](https://leumas.tech/contact)
- [Web Browser Pass View Software](https://www.nirsoft.net/utils/web_browser_password.html)
- [DOCS](https://cookbook.leumas.tech/docs/how-to-build-password-stealing-usb-rubber-ducky-with-arduino/)

## Getting Started

To create your own Arduino Micro BadUSB prototype, follow these steps:

### 1. Prepare the Software

- Visit [NirSoft](https://www.nirsoft.net/utils/web_browser_password.html) and download the WebBrowserPassView software.
- Paste the downloaded software onto a separate USB drive. Keep this USB drive on standby.

### 2. Prepare the Arduino Micro

- Upload the provided Arduino code to your Arduino Micro prototype. The code in this repository is designed to automate the execution of the WebBrowserPassView software and handle the extraction and saving of passwords.

### 3. Prepare the Micro SD Card

- Find a micro SD card and create a text file named `script.txt` on it. For this prototype, the `script.txt` should contain a single line of text: `PASSWORDSOFTWARE`.
- Save the text file on the micro SD card.
- Insert the micro SD card into the Arduino Micro.

### 4. Finalize the Setup

- Turn off and then turn on your Arduino Micro. Your device should now be ready to go.

![USB Circuit Prototype](https://res.cloudinary.com/dx25lltre/image/upload/v1711033666/CircuitDiagram_sls1gu.png)

*Please replace `your_image_link_here.png` with the actual link to your USB circuit image hosted online.*

## Blog Post

For more detailed information about this device, its development process, and its uses, check out our blog post: [Link to Blog Post](https://cookbook.leumas.tech/docs/how-to-build-password-stealing-usb-rubber-ducky-with-arduino/)

## Note

This project is intended for educational purposes and ethical use only. Ensure you have permission to run the WebBrowserPassView software and access the data it retrieves. Unauthorized use of this device and software could violate privacy rights and laws.
