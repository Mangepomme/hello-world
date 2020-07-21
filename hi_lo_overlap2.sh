./../setsched G-RES ;
./../resctl -n 100 -c 1 -t table-driven -m 200 '[20,70]' ;
./../resctl -n 101 -c 0 -t table-driven -m 200 '[90,190]' ;
./../resctl -n 102 -c 0 -t table-driven -m 200 '[80,130]' ;
./../rtspin -w -v -p 0 -r 100 -H '100,101' 40 200 1 &
./../rtspin -w -v -p 0 -r 102 -z 4 40 200 1 &
sleep 1 ;
./../release_ts ;
