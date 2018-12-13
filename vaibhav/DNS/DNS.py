'''
ASSIGNMENT NO:-11

TITLE:-Write a program for dns lookup given an ip address as a input it should return URL and vice versa.
'''

import socket
choose=True
while choose:
	print("\n1.host by name\n2.host by addrsss\n3.exit")
	choose=raw_input("\nenter the choice:")
	if choose=="1":
		siteURL = raw_input("enter the url ")
		addre1=socket.gethostbyname(siteURL)
		print(addre1)
	elif choose=="2":
		siteIP = raw_input("enter the IP address ")
		addre2=socket.gethostbyaddr(siteIP)
		print(addre2)
	elif choose=="3":
		exit()
	else:
		print("unknown")
'''
OUTPUT:-

res@res-HP-280-G2-MT-Legacy:~/Downloads$ python assign.py

1.host by name
2.host by addrsss
3.exit

enter the choice:1
216.58.203.142

1.host by name
2.host by addrsss
3.exit

enter the choice:2
('bom07s01-in-f142.1e100.net', [], ['216.58.199.142'])

1.host by name
2.host by addrsss
3.exit

enter the choice:3
'''
