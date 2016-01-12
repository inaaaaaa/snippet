#!/bin/bash
set -eu

LOCAL_TMP_DIR="/tmp"

function log() {
  _type=$1
  _msg=$2
  _date=$(date +"%y/%m/%d %H:%M:%S")
  case $_type in
    info) echo "${_date} INFO ${_msg}";;
    warn) echo "${_date} WARN ${_msg}";;
    error) echo "${_date} ERROR ${_msg}";;
    *) exit 1;;
  esac
}

function clean() {
  log info "==== clean ===="
#  rm -rf $LOCAL_TMP_DIR/*
}

function setup() {
  log info "==== setup ===="
  clean
}

function test0() {
  log info "==== test0 ===="
  _actual=$(echo "foofoo")
  _expected="foofoo"
  diff <(echo $_actual) <(echo $_expected) > /dev/null
  if [ $? -eq 0 ]; then
    log info "==== pass : test0 ===="
  else
    log error "==== fail : test0 ===="
    clean
    exit 1
  fi
}

function teardown() {
  log info "==== teardown ===="
  clean
}

# main
log info "==== start ===="
set +e
setup
set -e
test0
teardown
log info "==== complete ===="
