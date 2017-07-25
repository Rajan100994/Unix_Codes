mkdir dir1
cd dir1
mkdir dir4
cd dir4
touch file4

cd ../..

mkdir dir2
cd dir2
mkdir dir5

cd ..

mkdir dir3
cd dir3
touch file3

cd ..

touch file1
touch file2
cd dir2/dir5

ln -s ../../dir3/file3 link1
