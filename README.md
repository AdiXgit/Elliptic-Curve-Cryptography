# Elliptic Curve Cryptography
This project aims to implement basic Elliptic Curve Cryptography (ECC) , providing to a better alternative compared to RSA (STILL BUILDING :| )

## Overview

Welcome to the **Elliptic Curve Cryptography (ECC)** project! This project implements a basic ECC library in C, providing functionalities for key generation, digital signatures (ECDSA), and point operations on elliptic curves. ECC is a powerful cryptographic technique that offers strong security with smaller key sizes compared to traditional methods.

## Features

- **Key Generation**: Generate public and private key pairs using elliptic curves.
- **Digital Signatures**: Sign messages and verify signatures using the Elliptic Curve Digital Signature Algorithm (ECDSA).
- **Point Operations**: Perform addition and multiplication of points on elliptic curves.
- **Customizable Curves**: Define your own elliptic curves with parameters \(a\), \(b\), and \(p\).

## Getting Started

### Prerequisites

- **GCC**: Ensure you have GCC installed on your system. You can install it using the following commands:

  - **Ubuntu/Debian**:
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```

  - **Fedora**:
    ```bash
    sudo dnf install gcc gcc-c++
    ```

  - **macOS**:
    ```bash
    brew install gcc
    ```

  - **Windows**: Use MinGW or WSL to install GCC.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/ecc_project.git
   cd ecc_project/src
   ```


### WHY ECC IS BETTER ??
 🔒 More Secure with Smaller Keys

 -A 256-bit ECC key provides the same security as a 3072-bit RSA key.

 -A 384-bit ECC key is equivalent to 7680-bit RSA.

 -This means ECC is harder to break with brute force attacks.

 ⚡ Faster and More Efficient

 -ECC uses smaller numbers, making it faster for encryption, decryption, and signing.

-RSA requires large exponentiations, which are slower.

 📉 Less Storage & Bandwidth

-Smaller keys = less memory usage and faster communication.

-ECC is ideal for mobile devices, IoT, and blockchain where efficiency matters.








 
