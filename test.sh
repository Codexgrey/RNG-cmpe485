echo "Running tests..."
echo

output=$(./sim)

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

echo
echo "Simple tests OK!"

exit 0