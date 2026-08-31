#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init m_init(void){
	pr_info("Module is initialized");
	printk(KERN_INFO "Welcome");
	return 0;
}
static void __exit m_exit(void){
	printk(KERN_INFO "Module exit");
}
module_init(m_init);
module_exit(m_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AKHIL");
MODULE_DESCRIPTION("This is 1st driver");
MODULE_VERSION("1.1.0");
