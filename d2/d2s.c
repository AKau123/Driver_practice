#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

dev_t dev=MKDEV(500,0);

static int __init dd_init(void){
	register_chrdev_region(dev,1,"Prac");
	printk(KERN_INFO "Major:%d, Minor:%d", MAJOR(dev), MINOR(dev));
	pr_info("Device driver inserted");
	return 0;
}
static void __exit dd_exit(void){
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "Kernel Module removed");
}
module_init(dd_init);
module_exit(dd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AKHIL");
MODULE_DESCRIPTION("STATICALLY ALLOCATED DEVICE");

