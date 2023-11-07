# how tu use :
# in terminal :
#   sh ./compil.sh filename.c
# condensed version : sh ./com*sh filen*c
sci(){
    clear
    gcc -c $( echo "$1") 
    gcc $( echo "${1/.c/'.o'}") -o $( echo "${1/.c/'.sh'}") 
    "./$( echo "${1/.c/'.sh'}")"        
}
sci $1
# end page