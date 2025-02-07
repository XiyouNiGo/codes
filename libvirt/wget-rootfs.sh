#!/bin/bash
set -ex
rootfsDir="/var/run/kubevirt-private/vmi-disks/rootfs"
scratchImg="${rootfsDir}/scratch.img"
diskImg="${rootfsDir}/disk.img"
if [[ -f ${diskImg} ]]; then
	exit 0
fi
imageSize=""
while getopts "f:s:" opt; do
	case "$opt" in
	s)
		imageSize="${OPTARG}"
		;;
	*)
		exit 0
		;;
	esac
done
shift $((OPTIND - 1))
echo "size: ${imageSize}"
imageUrl=$1
echo "url: ${imageUrl}"
wgetExitCode=0
counter=0
wgetRetry=3
wget -O ${scratchImg} "$imageUrl" || wgetExitCode=$?
while [[ $wgetExitCode != 0 ]]; do
	echo "wget exit code: ${wgetExitCode}, try counter: ${counter}"
	sleep 15
	wgetExitCode=0
	wget -O ${scratchImg} "$imageUrl" || wgetExitCode=$?
	let counter=counter+1
	[[ $counter == $wgetRetry ]] && echo "reach maximum wget retries: ${wgetRetry}" && exit 1
done
chmod 666 ${scratchImg}
if [[ "${imageSize}" != "" ]]; then
	qemu-img resize "${scratchImg}" "${imageSize}"
fi
mv ${scratchImg} ${diskImg}root
