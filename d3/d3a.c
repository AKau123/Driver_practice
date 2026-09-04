//automatic device file creation => addition with class and device funcs
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/module.h>
#include <linux/err.h>

dev_t dev=0;
static struct class *devcl;

static int __init dd_init(void){
	if(alloc_chrdev_region(&dev,0,1,"pr")<0){
		pr_err("Failed");
		return -1;
	}
	pr_info("Major:%d, Minor:%d", MAJOR(dev), MINOR(dev));
	devcl= class_create("pr_class");
	if(IS_ERR(devcl)){
		pr_err("Class not created");
		goto r_class;
	}
	if(IS_ERR(device_create(devcl, NULL, dev, NULL, "pr_device"))){
		pr_err("Device not created");
		goto r_device;
	}
	pr_info("Device created");
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
	unregister_chrdev_region(dev,1);
	pr_info("Module exited");
}
module_init(dd_init);
module_exit(dd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AKHIL");
MODULE_DESCRIPTION("Automatic allocation of device file");



