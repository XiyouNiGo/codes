#!/usr/bin/env bash

virt-install \
	--name master \
	--memory 1024 \
	--vcpus 2 \
	--network network=default \
	--graphics none \
	--noautoconsole \
	--os-variant debian10 \
	--disk /root/linkai/master.img \
	--import
