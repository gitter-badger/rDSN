#!/bin/bash



PREFIX=$(readlink -m $(dirname ${BASH_SOURCE}))
export LD_LIBRARY_PATH=${PREFIX}

META_IP=${META_IP:-"$(cat ${PREFIX}/metalist)"}
META_IP=${META_IP#*@}
APP=${APP:-"${PREFIX##*/}"}

PROGRAM=${PREFIX}/simple_kv
CONFIG=${PREFIX}/config.ini
ARGS="-cargs 'meta-ip=${META_IP};data-dir=${PREFIX}' -app ${APP}"

${PROGRAM} ${CONFIG} ${ARGS} &>${PREFIX}/${APP}.out
