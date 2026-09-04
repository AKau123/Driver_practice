Linux Character Driver Development — Day-Wise Tutorials

This repository contains a day-wise, hands-on learning series for Linux Character Device Driver development, starting from the fundamentals and gradually building a complete character driver.

Each day focuses on a specific concept and builds upon the implementation from the previous day.

📚 Day-Wise Learning Path

Day 1 — Introduction to Character Drivers

Introduction to the basic structure of a Linux Character Device Driver.

Topics covered:

Kernel module basics
Driver initialization and cleanup
module_init() and module_exit()
Basic insmod, rmmod, and dmesg usage

Day 2 — Device Registration & Major/Minor Numbers

Understanding how a character device is registered with the Linux kernel and how major and minor device numbers are assigned.

Methods covered:

Direct allocation: alloc_chrdev_region()
Static/indirect registration: register_chrdev_region()
Understanding major and minor numbers
Checking registered device numbers

 Day 3 — Device File Creation

Learning how the device node is created and made accessible from user space.

Methods covered:

Manual device creation

Using mknod
Major/minor number assignment
Device file permissions
Creating the device node after module insertion

Automatic device creation

Creating a device class using class_create()
Creating the device using device_create()
Automatic creation of the device node under /dev/

Day 4 — CDEV & File Operations

Completing the character driver by integrating cdev and file operations with automatic device-file creation.

Topics covered:

struct cdev
cdev_init()
cdev_add()
struct file_operations
Implementing driver callbacks such as:
open()
read()
write()
release()
Automatic device allocation and creation
Complete character-driver workflow

This implementation provides a cleaner, faster, and easier-to-use driver workflow compared with manually creating the device node.
