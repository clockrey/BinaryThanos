# BinaryThanos

BinaryThanos is a utility designed to bring balance to your filesystem, selectively snapping away binary files with a 50% chance. Inspired by the decisiveness of Thanos from the Marvel Universe and Ed posts on the COMP2017 forum, this tool aims to reduce clutter in your directories by half, targeting binary files that might no longer be necessary. You'll receive a mark deduction half the time!

![thanosSnap](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExbHQ1bHVhd29iYTAxNHAwNDgyYnpsdWExOTgyOHF4cjk4dmw0and6NiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/xUOxeZn47mrdabqDNC/giphy.gif)

## Description

BinaryThanos traverses a specified directory, examining each file to determine if it is a binary file. If a file is identified as binary, there's a 50% chance it will be deleted - perfectly balanced, as all things should be. This process mimics the randomness of Thanos' snap, providing a fun and risky way to clean up your files.

## Installation

To use BinaryThanos, simply compile the source code with a C compiler such as GCC:

```bash
gcc -o BinaryThanos BinaryThanos.c
```

## Usage

To unleash BinaryThanos on a directory, run:

```bash
./BinaryThanos <directory_path>
```

Ensure you have the permissions required to read and delete files in the directory.

## How It Works

- **File Determination**: BinaryThanos determines if a file is binary by reading its contents. If it encounters a null byte or control characters (other than newlines, carriage returns, and tabs), it deems the file as binary.
- **Random Deletion**: For each binary file found, there's a 50% chance it will be deleted. This process is logged in the console, informing you which files were considered for deletion and which were actually removed.

## Disclaimer

BinaryThanos is a project for entertainment purposes. Running this utility can result in the loss of important files. It's recommended to use it on test directories or where you are sure of the contents you might lose.

## Contributing

Feel free to fork the project and submit pull requests. Ideas for improvements, bug reports, and general feedback are always welcome. Let's make BinaryThanos as effective and fun as possible!