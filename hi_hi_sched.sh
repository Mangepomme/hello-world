./../setsched G-RES ;
./../resctl -n 100 -c 1 -t table-driven -m 200 '[10,50]' ;
./../resctl -n 101 -c 0 -t table-driven -m 200 '[90,190]' ;
./../resctl -n 102 -c 0 -t table-driven -m 200 '[30,70]' ;
./../resctl -n 103 -c 1 -t table-driven -m 200 '[90,190]' ; 
./../rtspin -w -v -p 0 -r 100 -H '100,101' -z 4 40 200 1 &
./../rtspin -w -v -p 0 -r 102 -H '100,103' 40 200 1 &
sleep 1 ;
./../release_ts ;
