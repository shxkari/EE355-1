class node:
	def __init__(self,data=None):
		self.data=data
		self.next=None

class linked_list:
	def __init__(self):
		self.head=node()

	def append(self,data):
		new_node=node(data)
		current=self.head
		while current.next!=None:
			current=current.next
		current.next=new_node

	def length_of_list(self):
		current=self.head
		total=0
		while current.next!=None:
			total+=1
			current=current.next
		return total 
 
	def display_list(self):
		elements=[]
		current_node=self.head
		while current_node.next!=None:
			current_node=current_node.next
			elements.append(current_node.data)
		print(elements)
 
	def get_value(self,idx):
		if idx>=self.length_of_list() or idx<0:
			print("Index----out of range!")
			return None
		current_idx=0
		current_node=self.head
		while True:
			current_node=current_node.next
			if current_idx==idx: return current_node.data
			current_idx+=1

	def remove(self,idx):
		if idx>=self.length_of_list() or idx<0:
			print("Index----out of range!")
			return 
		current_idx=0
		current_node=self.head
		while True:
			last_node=current_node
			current_node=current_node.next
			if current_idx==idx:
				last_node.next=current_node.next
				return
			current_idx+=1

	def add(self,idx,data):
		if idx>=self.length_of_list() or idx<0:
			return self.append(data)
		current_node=self.head
		prev_node=self.head
		current_idx=0
		while True:
			current_node=current_node.next
			if current_idx==idx: 
				new_node=node(data)
				prev_node.next=new_node
				new_node.next=current_node
				return
			prev_node=current_node
			current_idx+=1

	def reverse(self):
		current_node=self.head
		current_node=current_node.next
		next_node=current_node.next
		while True:
			if(next_node==None):
				return
			dat1=current_node.data
			dat2=next_node.data
			current_node.data=dat2
			next_node.data =dat1
			current_node=next_node.next
			next_node=current_node.next
			




new_list = linked_list()

new_list.append("shahin")
new_list.append("nazarian")
new_list.append("sufyan")
new_list.append("shaikh")
new_list.append("donald")
new_list.append("trump")
new_list.append("obama")

new_list.display_list()

idx_erase = input("Which index would you like to remove? \n")
new_list.remove(idx_erase)
new_list.display_list()

idx_add = input("Which index would you like to add data to?\n")
data = input("What would you like to add to this index?\n(please use quotations if adding a string)\n")
new_list.add(idx_add,data)
print "After adding new index:"
new_list.display_list()

new_list.reverse()
print "After reversing list:"
new_list.display_list()

