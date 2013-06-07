#ifndef LIBOSNSTOR_H_
#define LIBOSNSTOR_H_
#include "list.h"

#define CHAR_LEN 64

struct scsi_host {
	struct list_head host_entry;

	/* device list of this host*/
	struct list_head dev_list;

	/* host unique identifier */
	unsigned int host_id;

	/*host name, for example host1,host2 */
	const char hostname[CHAR_LEN];

	/* qla2xxx/iscsi_tcp/... */
	const char driver_type[CHAR_LEN];

	unsigned int transport_type;

	const char port_name;
	uint32_t port_id;
};

struct scsi_dev {
	struct list_head dev_entry;

	unsigned int host, channel, target, lun;
	unsigned int major, minor;

	const char vendor[CHAR_LEN];
	const char model[CHAR_LEN];
	const char rev[CHAR_LEN];

	char type;
	char scsi_level;

	unsigned sector_size;

	/* for block device */
	uint64_t size;
	unsigned int queue_type;
	unsigned int queue_depth;

	unsigned int status;
};
#endif /* LIBOSNSTOR_H_ */

