# CS1300 Fall 2017
# Author: 
# Recitation: 
# Assignment 10


#PART_1 functions here

#create a list, open the file, and test to see if it opened
#read each line of the file, determine if the length is 0, if so return the empty list 
#read all the lines in the file, and store them in list words
#for each line, strip and split at comma, this will store in subList
#make a new Sublist1, which flipflops the data(because it was in the reverse order)
#append Sublist1 to complete list and return 
def read_books(file_name):
	completeList = []
	try: 
		dataFile = open(file_name)
	except: 
		return None
	words = dataFile.readlines()
	if len(words) == 0:
		return completeList
	for line in words:
		subList = line.strip().split(',')
		subList1 = []
		subList1.append(subList[1])
		subList1.append(subList[0])
		completeList.append(subList1)
	return completeList

#create a new dictionary, check to see if the file opened
#read each line in the file and store in list words, if length of list is 0, return empty dict
#for each index in words list(which is a string), split the string and store in subList
#make new list, store the first index(which is name) in name list and delete that name from the OG list 
#the dict id is now namelist, and set it equal to the all the values in the sublist (i did a shorthand way)
def read_users(user_file):
	myDict = {}
	try:
		dataFile = open(user_file)
	except:
		return None
	words = dataFile.readlines()
	if len(words) == 0:
		return myDict
	for line in words:
		nameList = []
		subList = []
		subList = line.split()
		nameList = subList[0] #namelist now has the name in it
		subList.pop(0) #sublist now has all the corresponding numbers in it
		myDict[nameList] = [int(x) for x in subList]
		
		#namelist = []
		#for x in subList: 
		#	namelist.append(int(x))
		#myDict[nameList] = nameList 
	
	return myDict
#create new list, average and summation, check to see if the first key in the dictionary's values is 0, if so, return empty list
#loop through the length of the first key's values in the ratings dict
#create a temp list that for a specific users values in the dictionary 
#loop through the temp list, if the score != 0, add it up, count++ then average = sum / count
#append that average to a average list and return 
def calculate_average_rating(ratings_dict):
	averageList = []
	summation = 0.0
	avg = 0.0
	if len(ratings_dict[ratings_dict.keys()[0]]) == 0:
		return averageList
	for i in range(len(ratings_dict[ratings_dict.keys()[0]])):
		count = 0
		summation = 0 
		for user in ratings_dict:
			tempList = ratings_dict[user]
			if tempList[i] != 0:
				summation = summation + (tempList[i])
				count = count + 1
		avg = float(summation) / count
		averageList.append(avg)
	return averageList
	
#set book and user to the corresponding indexs in the book dictionary
#set rating equal to the funciton call of average radings of the index
#return proper string 
def lookup_average_rating(index, book_dict, average_ratings_dict):
	book = book_dict[index][0]
	user = book_dict[index][1]
	rating = average_ratings_dict[index]
	return "(%.2f) %s by %s" % (rating, book, user)


#PART_2 follow here
#the first four functions are the same logic though instead of returning lists/dicts you fill the lists/dicts provided in the constructor
#declare the proper functions in the constructor, so when you create a an object, that obect has the proper data (specifically calc_average_ratings)
class Recommender():
	def __init__(self, books_filename, ratings_filename):
		self.book_list = []
		self.user_dictionary = {}
		self.average_rating_list = []
		self.read_books(books_filename)
		self.read_users(ratings_filename)
		self.calculate_average_rating()
	
	def read_books(self, file_name):
		try: 
			dataFile = open(file_name)
		except: 
			return None
		words = dataFile.readlines()
		if len(words) == 0:
			return self.book_list
		for line in words:
			subList = line.strip().split(',')
			subList1 = []
			subList1.append(subList[1])
			subList1.append(subList[0])
			self.book_list.append(subList1)


	def read_users(self, user_file):
		try:
			dataFile = open(user_file)
		except:
			return None
		words = dataFile.readlines()
		if len(words) == 0:
			return self.user_dictionary
		for line in words:
			nameList = []
			subList = []
			subList = line.strip().split()
			nameList = subList[0]
			subList.pop(0)
			self.user_dictionary[nameList] = [int(x) for x in subList]
			
			
	def calculate_average_rating(self):
		self.average_rating_list = []
		summation = 0.0
		avg = 0.0
		if len(self.user_dictionary[self.user_dictionary.keys()[0]]) == 0:
			return self.average_rating_list
		for i in range(len(self.user_dictionary[self.user_dictionary.keys()[0]])):
			count = 0
			summation = 0 
			for user in self.user_dictionary:
				tempList = self.user_dictionary[user]
				if tempList[i] != 0:
					summation = summation + (tempList[i])
					count = count + 1
			avg = float(summation) / count
			self.average_rating_list.append(avg)
		
		
	def lookup_average_rating(self, index):
		rating = []
		book = self.book_list[index][0]
		user = self.book_list[index][1]
		rating = self.average_rating_list[index]
		return "(%.2f) %s by %s" % (rating, book, user)

#create two seperate lists that are filled with the specific data fromt user_dictionary
#initialize sum, and loop through the size of the lists(55)
#multiply i in list one by i in list two, add it to the sum and return 
	def calc_similarity(self, user1, user2):
		list1 = self.user_dictionary[user1]
		list2 = self.user_dictionary[user2]
		summation = 0.0
		for i in range(0, 55):
			summation = summation + (list1[i] * list2[i])
		return int(summation)
		
#loop through the keys in the dictionary 
#if i does not equal the current id(dont want to compaire yourself)
#totalscore is the value returned by compairing the given user and the current user in the loop
#find the max, set user equal to that index and return user  	
	def get_most_similar_user(self, current_user_id):
		currMax = 0
		user = ''
		totalScore = 0
		for i in self.user_dictionary.keys():
			if i != current_user_id:
				totalScore = self.calc_similarity(current_user_id, i)
				if totalScore > currMax:
					currMax = totalScore
					user = i
		return user
		
#initialize a list to return 
#create a similarUser and bestUser list and store them with the corresponding data 
#loop through the length of of of the lists (they are the same size)
#if givenUserList == 0 (book has not ben read) && the bestUser has a rating greater equal to 3 and equal to 5
#if those criteria is satisfied, add the average ratings of that user to the return list
#return list 
	def recommend_books(self, current_user_id):
		recList = []
		similarUser = self.get_most_similar_user(current_user_id)
		bestUserList = self.user_dictionary[similarUser]
		givenUserList = self.user_dictionary[current_user_id]
		for j in range(len(bestUserList)):
			if givenUserList[j] == 0:
				if bestUserList[j] == 3 or bestUserList[j] == 5:
					recList.append(self.lookup_average_rating(j))
		return(recList)

def main():

	#read_books
	x = read_books('book.txt')
	print x
	
	#read_users
	y = read_users('ratings.txt')
	print y 

	#calculate_average_ratings
	z = calculate_average_rating(read_users('ratings.txt'))
	print z 

	#lookup_average_rating
	list1 = read_books('book.txt')
	list2 = calculate_average_rating(read_users('ratings.txt'))
	print lookup_average_rating(4, list1, list2)
	
	newObject = Recommender('book.txt', 'ratings.txt')
	print(newObject.read_books('book.txt'))
	print(newObject.read_users('ratings.txt'))
	print(newObject.calculate_average_rating())
	print(newObject.lookup_average_rating(0))
	print(newObject.calc_similarity('Cust10', 'ROFLOL'))
	print(newObject.get_most_similar_user('ender')) 
	print(newObject.recommend_books('Megan'))

if __name__ == "__main__":
    main()
