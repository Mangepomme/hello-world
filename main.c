#include <linux/mutex.h>
#include <linux/gpio/driver.h>
#include <linux/gpio/consumer.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/spi/spi.h>
#include <linux/mod_devicetable.h>
#include <linux/of_device.h>

MODULE_AUTHOR("Groupe 9");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Driver pour le chip MFRC522");

/* local definition */
struct chip_dev {
        struct cdev cdev;
        size_t size;
        char *buffer;
};


static int major;
static struct chip_dev *chip_dev;

/* Char device file operations */
int chip_open(struct inode *inode, struct file *filp)
{
        unsigned int i_major = imajor(inode);
        unsigned int i_minor = iminor(inode);

        if (i_major != major) {
                pr_err("Invalid major %d, expected %d\n", i_major, major);
                return -EINVAL;
        }

        if (i_minor != 0) {
                pr_err("This driver only handles minor 0!\n");
                return -EINVAL;
        }

        return 0;
}

ssize_t chip_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
/*        struct chip_dev *my_data = (struct chip_dev *)filp->private_data;
        ssize_t size;
        if (my_data->size - *off < len)
                size = my_data->size - *off;
        else
                size = len;
        if (size <= 0)
                return 0;

        if (copy_to_user(buf, my_data->buffer + *off, size))
                return -EFAULT;

        *off += size;*/
        return len;
}

int chip_release(struct inode *inode, struct file *filp)
{
        /* Nothing to do in particular */
        return 0;
}

ssize_t chip_write(struct file *filep, const char __user *buf, size_t len,
        loff_t *off)
{
        //TODO
        return len;
}

static struct file_operations chip_fops = {
        .owner = THIS_MODULE,
	.open = chip_open,
	.read = chip_read,
	.write = chip_write,
	.release = chip_release
};

/* Init and exit */

__init
static int chip_init(void) {

        dev_t dev;
        int ret;
        const char devname[] = "chip";

        // allocate major
        ret = alloc_chrdev_region(&dev, 0, 1, devname);
        if (ret < 0) {
                pr_err("Failed to allocate major");
                return 1;
        }
        else {
                major = MAJOR(dev);
        }

        // allocate char device
        chip_dev = kmalloc(sizeof(*chip_dev), GFP_KERNEL);
        if (! chip_dev) {
                pr_err("Failed to allocate struct chip_dev");
                return -ENOMEM;
        }
        
        // register char device 
        chip_dev->cdev.owner = THIS_MODULE;
        cdev_init(&chip_dev->cdev, &chip_fops);
        ret = cdev_add(&chip_dev->cdev, dev, 1);
        if (ret < 0) {
                pr_err("Failed to register char device");
                return -ENOMEM;
        }

        pr_info("Hello, card reader!\n");
        return 0;
}

__exit
static void chip_exit(void) {
        dev_t dev;

        // unregister char device
        cdev_del(&chip_dev->cdev);

        // free char device
        kfree(chip_dev);

        // release major
        dev = MKDEV(major, 0);
        unregister_chrdev_region(dev, 1);
}

/* probe and remove */
int chip_probe(struct spi_device *spi_dev)
{
        pr_info("probe\n");
	chip_init();
        return 0;
}

int chip_remove(struct spi_device *spi_dev)
{
        pr_info("remove\n");
	chip_exit();
        return 0;
}


static const struct of_device_id chip_id[] = {
        {.compatible = "nxp.mfrc522"},
        {}
};
MODULE_DEVICE_TABLE(of, chip_id);

static struct spi_driver chip_driver = {
        .driver = {
                .name = "chip_driver",
                .owner = THIS_MODULE,
                .of_match_table = chip_id
        },
        .probe = chip_probe,
        .remove = chip_remove
};

//module_init(chip_init);
//module_exit(chip_exit);
module_spi_driver(chip_driver);
