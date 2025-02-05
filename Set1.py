'''
To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection, d. Size () Return number of
values in collection Iterator () Return an iterator used to loop over collection, e.
Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset
'''

a = {11, 25, 39, 14, 5}
b = {39, 14, 5, 62, 78}
class ADTSet:
   def Add_element(self,val,Set):
     Set.add(val)
     print(val," is added to set :",Set)
   def Delete_element(self,val,Set):
     Set.remove(val)
     print(val, " is Deleted from set ", Set)
   def Is_contain(self,val,Set):
      if val in Set:
         print(val," is contains in set :",Set)
      else:
         print(val, " is not contains in set :", Set)
   def Size_of_set(self,Set):
     x=len(Set)
     print("Size of Set :",Set," is :",x)
   def Union(self,Seta,Setb):
      return Seta.union(Setb)
   def Intersection(self,Seta,Setb):
      return Seta.intersection(Setb)
   def Difference(self,Seta,Setb):
      return Seta.difference(Setb)
   def Is_subset(self, Seta, Setb):
      if Seta.issubset(Setb):
         print("Set A is a subset of Set B")
      else:
          print("Set A is not a subset of Set B")
obj=ADTSet()
print("Given sets are: \n Set A: ", a, "\n Set B: ", b)
while(True):
  print("Select operation to perform: ")
  print("\n1.Add \n2.Remove \n3.Contain \n4.Size \n5.Intersection \n6.Union \n7.Difference \n8.Subset")
  ch=int(input("\nEnter your choice :"))
  if ch==1:
    s=int(input("Enter the set to add the element :\n1)Set A \n22)Set B \nEnter your choice :"))
    ele=int(input("\nEnter the element to add :"))
    if s==1:
       obj.Add_element(ele,a)
    if s==2:
       obj.Add_element(ele,b)
    if s==-1:
       exit(0)
  if ch==2:
    s2=int(input("Enter the set to Delete the element :\n1)Set A\n2)Set B\nEnter your choice :"))
    ele2 = int(input("\nEnter the element to Delete :"))
    if s2==1:
      obj.Delete_element(ele2,a)
    if s2==2:
      obj.Delete_element(ele2,b)
  if ch==3:
      s4=int(input("Enter the set to check the element :\n1)Set A\n2)Set B\nEnter your choice :"))
      ele4=int(input("Enter the element to check :"))
      if s4==1:
        obj.Is_contain(ele4,a)
      if s4==2:
        obj.Is_contain(ele4,b)
  if ch==4:
     s3=int(input("Enter the set to check size :\n1)Set A\n2)Set B\nEnter your choice :"))
     if s3==1:
        obj.Size_of_set(a)
     if s3==2:
        obj.Size_of_set(b)
  if ch==5:
    print("Intersection of the sets A and B is :",obj.Intersection(a,b))
    if ch==6:
       print("Union of the sets A and B is :",obj.Union(a,b))
  if ch==7:
    print("Difference of the sets A and B is :", obj.Difference(a,b))
    print("Difference of the sets B and A is :", obj.Difference(b,a))
  if ch==8:
    s5 = int(input("Enter the set to check the Subset or not :\n1)Set A\n2)Set B\nEnter your choice :"))
    if s5==1:
      obj.Is_subset(a,b);
    if s5==2:
       obj.Is_subset(b,a);

