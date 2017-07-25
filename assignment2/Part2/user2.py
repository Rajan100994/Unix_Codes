import re

var = raw_input("Enter user-name: ")

file = open("passwd1.txt", "r")

for line in file:
    if re.search(var,line):
        ans = line
#print "you entered", var
part = ans.split(':')
print("userid: " + part[0])
print("uid: " + part[2])
print("gid: " + part[3])
print("home directory: " + part[5])
print("shell: " + part[6])
