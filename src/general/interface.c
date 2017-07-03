    
    #include "interface.h"

    interface_obj * interface_construct() {

        interface_obj * obj;

        obj = (interface_obj *) malloc(sizeof(interface_obj));

        // +----------------------------------------------------------+
        // | Type                                                     |
        // +----------------------------------------------------------+

            obj->type = interface_undefined;

        // +----------------------------------------------------------+
        // | File                                                     |
        // +----------------------------------------------------------+

            obj->fileName = (char *) NULL;

        // +----------------------------------------------------------+
        // | Socket                                                   |
        // +----------------------------------------------------------+

            obj->ip = (char *) NULL;
            obj->port = 0;

        // +----------------------------------------------------------+
        // | Soundcard                                                |
        // +----------------------------------------------------------+

            obj->device = 0;
            obj->subdevice = 0;

        return obj;

    }

    interface_obj * interface_construct_file(const char * fileName) {

        interface_obj * obj;

        obj = (interface_obj *) malloc(sizeof(interface_obj));

        // +----------------------------------------------------------+
        // | Type                                                     |
        // +----------------------------------------------------------+

            obj->type = interface_file;

        // +----------------------------------------------------------+
        // | File                                                     |
        // +----------------------------------------------------------+

            obj->fileName = (char *) malloc(sizeof(char) * (strlen(fileName)+1));
            strcpy(obj->fileName, fileName);

        // +----------------------------------------------------------+
        // | Socket                                                   |
        // +----------------------------------------------------------+

            obj->ip = (char *) NULL;
            obj->port = 0;

        // +----------------------------------------------------------+
        // | Soundcard                                                |
        // +----------------------------------------------------------+

            obj->device = 0;
            obj->subdevice = 0;

        return obj;

    }

    interface_obj * interface_construct_socket(const char * ip, const unsigned int port) {

        interface_obj * obj;

        obj = (interface_obj *) malloc(sizeof(interface_obj));

        // +----------------------------------------------------------+
        // | Type                                                     |
        // +----------------------------------------------------------+

            obj->type = interface_socket;

        // +----------------------------------------------------------+
        // | File                                                     |
        // +----------------------------------------------------------+

            obj->fileName = (char *) NULL;

        // +----------------------------------------------------------+
        // | Socket                                                   |
        // +----------------------------------------------------------+

            obj->ip = (char *) malloc(sizeof(char) * (strlen(ip)+1));
            strcpy(obj->ip, ip);
            obj->port = port;

        // +----------------------------------------------------------+
        // | Soundcard                                                |
        // +----------------------------------------------------------+

            obj->device = 0;
            obj->subdevice = 0;

        return obj;        

    }

    interface_obj * interface_construct_soundcard(const unsigned int device, const unsigned int subdevice) {

        interface_obj * obj;

        obj = (interface_obj *) malloc(sizeof(interface_obj));

        // +----------------------------------------------------------+
        // | Type                                                     |
        // +----------------------------------------------------------+

            obj->type = interface_soundcard;

        // +----------------------------------------------------------+
        // | File                                                     |
        // +----------------------------------------------------------+

            obj->fileName = (char *) NULL;

        // +----------------------------------------------------------+
        // | Socket                                                   |
        // +----------------------------------------------------------+

            obj->ip = (char *) NULL;
            obj->port = 0;

        // +----------------------------------------------------------+
        // | Soundcard                                                |
        // +----------------------------------------------------------+

            obj->device = device;
            obj->subdevice = subdevice;

        return obj;

    }

    interface_obj * interface_clone(const interface_obj * obj) {

        interface_obj * clone;

        clone = interface_construct();

        // +----------------------------------------------------------+
        // | Type                                                     |
        // +----------------------------------------------------------+

            clone->type = obj->type;        

        // +----------------------------------------------------------+
        // | File                                                     |
        // +----------------------------------------------------------+

            if (obj->type == interface_file) {
                
                clone->fileName = (char *) malloc(sizeof(char) * (strlen(obj->fileName) + 1));
                strcpy(clone->fileName, obj->fileName);

            }

        // +----------------------------------------------------------+
        // | Socket                                                   |
        // +----------------------------------------------------------+                

            if (obj->type == interface_socket) {
                
                clone->ip = (char *) malloc(sizeof(char) * (strlen(obj->fileName) + 1));
                strcpy(clone->ip, obj->ip);
                clone->port = obj->port;

            }

        // +----------------------------------------------------------+
        // | Soundcard                                                |
        // +----------------------------------------------------------+

            if (obj->type == interface_soundcard) {
                
                clone->device = obj->device;
                clone->subdevice = obj->subdevice;

            }

        return clone;

    }

    void interface_destroy(interface_obj * obj) {

        if (obj->fileName != NULL) {

            free((void *) obj->fileName);

        }

        if (obj->ip != NULL) {

            free((void *) obj->ip);

        }

        free((void *) obj);

    }

    void interface_printf(const interface_obj * obj) {

        if (obj != NULL) {

            switch(obj->type) {

                case interface_file:

                    printf("type = file, fileName = %s\n",obj->fileName);

                break;

                case interface_socket:

                    printf("type = socket, ip = %s, port = %u\n",obj->ip,obj->port);

                break;

                case interface_soundcard:

                    printf("type = soundcard, device = %u, subdevice = %u\n",obj->device,obj->subdevice);

                break;

            }

        }
        else {

            printf("(null)\n");

        }

    }