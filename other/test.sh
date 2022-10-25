#!/bin/bash

executable="./pipex"

#cmds
wrong_cmd1="\"lssd -l\""
wrong_cmd2="\"wccc -l\""
cmd1="\"ls -l\""
cmd2="\"wc -l\""

#files
no_infile="no_infile"
no_outfile="no_outfile"
infile="infile"
outfile="outfile"
bad_infile="bad_infile"
bad_outfile="bad_outfile"


test1=("$executable $infile $cmd1 $cmd2 $outfile")

eval $test1

#test1=("$executable $infile $cmd1 $cmd2 $outfile")
#$test1 2>&1

