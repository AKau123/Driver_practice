//Manually allocating device file

//First allocate device dynamically

#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>

dev_t dev=0;
static int __init dd_init(void){
	if((alloc_chrdev_region(&dev,0,1,"practice"))<0){
		pr_err("Failed");
		return -1;
	}
	pr_info("Registered, Major:%d, Minor:%d", MAJOR(dev), MINOR(dev));
	pr_info("Done");
	return 0;
}
static void __exit dd_exit(void){
	unregister_chrdev_region(dev,1);
	pr_info("Unregistered");
}

module_init(dd_init);
module_exit(dd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AKHIL");
MODULE_DESCRIPTION("MANUAL DEVICE FILE ALLOCATION");

