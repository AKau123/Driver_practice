#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
dev_t dev=0;

static int __init dd_init(void){
	if((alloc_chrdev_region(&dev,0,1,"prac"))<0){
		pr_info("Cannot allocate");
		return -1;
	}
	printk(KERN_INFO "Major:%d, Minor:%d", MAJOR(dev), MINOR(dev));
	pr_info("Allocated sucessfully");
	return 0;
}
static void __exit dd_exit(void){
	unregister_chrdev_region(dev,1);
	printk(KERN_INFO "Unregistered successfully");
}

module_init(dd_init);
module_exit(dd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AKHIL");
MODULE_DESCRIPTION("DYNAMIC ALLOCATED DD");
