#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/err.h>
#include <linux/cdev.h>

dev_t dev=0;
static struct class *devcl;
static struct cdev pr_cdev;

static int __init dd_init(void);
static void __exit dd_exit(void);
static int pr_open(struct inode*inode, struct file *file);
static int pr_release(struct inode*inode, struct file *file);
static ssize_t pr_read(struct file *filp,char __user *buf, size_t len, loff_t *off);
static ssize_t pr_write(struct file *filp,const char *buf, size_t len, loff_t *off);

static const struct file_operations fops ={
	.owner=THIS_MODULE,
	.open=pr_open,
	.release=pr_release,
	.read= pr_read,
	.write=pr_write,
};
static int pr_open(struct inode *inode, struct file *file){
       pr_info("Driver is open");
	return 0;
}
static int pr_release(struct inode *inode, struct file *file){
	pr_info("Driver is closed");
	return 0;
}
static ssize_t pr_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
	pr_info("Read function is called");
	return 0;
}
static ssize_t pr_write(struct file *filp,const char *buf, size_t len, loff_t *off){
	pr_info("Write function is called");
	return len;
}

static int __init dd_init(void){
	if(alloc_chrdev_region(&dev,0,1,"prac")<0){
		pr_err("Failed to register device");
		return -1;
	}

	cdev_init(&pr_cdev, &fops);
	if(cdev_add(&pr_cdev,dev,1)<0){
		pr_err("cannot add device to the system");
		goto r_class;
	}

	devcl=class_create("pr_class");
	if(IS_ERR(devcl)){
		pr_err("Class is not created");
		goto r_class;
	}
	if(IS_ERR(device_create(devcl,NULL,dev,NULL,"pr_device"))){
		pr_err("Device creation failed");
		goto r_device;
	}
	pr_info("Major:%d, Minor:%d", MAJOR(dev), MINOR(dev));
	return 0;
r_device:
	class_destroy(devcl);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}

static void __exit dd_exit(void){
	device_destroy(devcl,dev);
	class_destroy(devcl);
	cdev_del(&pr_cdev);
	unregister_chrdev_region(dev,1);
	pr_info("Modulle Unloaded");
}
module_init(dd_init);
module_exit(dd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AKHIL");
MODULE_DESCRIPTION("CDEV AND FILE OPS");

