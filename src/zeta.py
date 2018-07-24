#!/usr/bin/env python

import json


sink1 = {
    "sink": {
        "type": "stdout_sink_mt",
        "level": "trace"
        }
    }

sink2 = {
    "sink": {
        "type": "rotating_file_sink_mt",
        "level": "trace",
        "file_name": "zeta.log",
        "max_file_size": 5000000,
        "max_files": 10
        }
    }

log = {
    "level": "trace",
    "sinks": [sink1, sink2]
    }

zeta = {
        "instrus_filter": "",
        "speed_file": "zeta_speed.data"
    }

zebra = {
        "queue_size": 2097152, 
        "packet_type": 2,
        "optimization": False,
        "pcap_file": "x10_20180724_001.pcap"
    }

spy = {
        "device": "eth0", 
        "snaplen": 65535, 
        "promisc": 0, 
        "timeout": 0, 
        "nonblock": 1, 
        "filter": "udp port 12345"
    }

config = {
    "zeta": zeta,
    "zebra": zebra,
    "spy": spy,
    "log": log
    } 

with open('zeta.json', 'w') as f:
    json.dump(config, f, sort_keys=True, indent=4)

