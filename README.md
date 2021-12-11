# BMTagger
# Language: C++
# Input: TXT
# Output: LIST
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: BMTagger 1.1

Find host sequences with BMTagger (Rotmistrovsky and Agarwala, 2011)

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
config:  BMTagger config file, sets BMTAGGER_DB
bitmask: Bitmask file (usually output by BMTool)
srprism: SRPRISM file prefix
forward: FASTQ file for forward sequences
reverse: FASTQ file for reverse sequences

Host sequences will be sent to the output LIST file
