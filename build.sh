#!/bin/bash

set -e
set -u

THIS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

build_dir="${THIS_DIR}/_build"

mkdir -p "${build_dir}"
cd "${build_dir}"

cmake ..
cmake --build .