sci(){
    clear
    gcc -c $( echo "$1") 
    gcc $( echo "${1/.c/'.o'}") -o $( echo "${1/.c/'.sh'}") 
    "./$( echo "${1/.c/'.sh'}")"        
}
sci $1