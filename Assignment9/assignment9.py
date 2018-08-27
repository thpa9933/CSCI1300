#Thomas Payne
#Chelsea Chandler
#Assignment 9

#Part1 a
'''
take in a list, determine what index of that list applies to which given variable
variables = the year / given variable 
add the variables together and return 
'''
def compute_census(list_of_rates, current_population):
	year = 31536000
	birth = year / list_of_rates[0]
	death = year / list_of_rates[1]
	immigrant = year / list_of_rates[2]
	return current_population + birth - death + immigrant
	
		
#Part1 b
'''
take in a certain amount of seconds
if the seconds = 0, return the string with 0 seconds
else figure out the days, hours, minuets using mod function 
mod function essentially slims down the seconds with each day/hour/minuet taken off
return string with given variables 
'''
def convert_seconds():
	days = 0
	hours = 0
	minutes = 0
	total_seconds = input()
	seconds = total_seconds
	if total_seconds < 0:
		seconds = 0
		print(str(total_seconds) + "corresponds to: " + str(days) + " days, " + str(hours) + " hours, " + str(minutes) + " minutes, " + str(seconds) + " seconds.")

	else:
		days = seconds/86400
		seconds = seconds%86400
		hours = seconds/3600
		seconds = seconds%3600
		minutes = seconds/60
		seconds = seconds%60
		print(str(total_seconds) + " corresponds to: " + str(days) + " days, " + str(hours) + " hours, " + str(minutes) + " minutes, " + str(seconds) + " seconds.")
	
#Part 2
'''
initialize story to empty list
loop through parameter, startint at 1 because your first prompt is at one
skip by 2 because that is where your prompts are 
build to the story string by adding a space and adding the user answer to the prompts 
return story 
'''
def generate_story(list_to_story):
	story = ''
	for i in range(1,len(list_to_story), 2):
		story = story + list_to_story[i-1]
		story = story + ' '
		story = story + raw_input(list_to_story[i])
	return story
	
#Part 3 a
'''
recieve two sequences 
loop through the length of the sequences (only if the sequences are the same length) 
see if the index in one sequence does not equal the index in the other, if this is true mismatch++
calculate sim score
return sim score 
'''
def similarity_score(seq1, seq2):
	if len(seq1) == len(seq2):
		length = len(seq1)
		mismatch = 0.0
		sim_score = 0.0
		for i in range(0,length):
			if seq1[i] != seq2[i]:
				mismatch = mismatch + 1.0
		sim_score = (length - mismatch)/length
		return sim_score 
	else:
		return 0

#Part 3 b
'''
loop through the length of the genome
call the sim_score function, use a substrin like function for the parameter (include + i becuase you need to start the substring from i)
you do this to test the substring agains the given sequence 
find the largest score
mark best index at the index of the largest score 
return the best index 
'''
def best_match(genome, seq):
	i = 0
	best_score = 0.0
	best_i = 0
	sim_score = 0.0
	myList = []
	while i < len(genome):
		sim_score = similarity_score(seq, genome[i:len(seq)+i])
		if sim_score > best_score:
			best_score = sim_score
			best_i = i
			#myList.append(best_score)
		i = i + 1
	return best_i
	#return(myList.index(best_score))

#Part 4	
'''
create a finalArray to eventually store average and median into 
loop through the given list of numbers, add each index and divide by total indexs
store in first index of finalArray 
find median now, see if the list length is odd or even 
if it is odd, divide the list by 2 and return that number(it will be the middle number)
if it is even, add the two middle most numbers and divide by two
add the median to the second index in the finalArray
return finalArray 
'''
def calc_stats(list_of_numbers):
	finalArray = ['', '']
	average = 0
	i = 0
	sum = 0.0
	size = len(list_of_numbers)
	while i < size:
		sum += list_of_numbers[i]
		i += 1
	average = sum / i 
	finalArray[0] = average 
	
	median = 0
	if size%2 != 0:
		median = list_of_numbers[size/2]
		finalArray[1] = median
	else:
		median = (list_of_numbers[size/2] + list_of_numbers[(size/2) - 1]) / 2.0
		finalArray[1] = median
	return finalArray

#Part 5 
'''
open file
create a list that splits the origional line ( this list now contains the name, and a string of numbers seperated by space)
create a namelist that stores the first index from the origional list 
create a number list that stores the last index from the origional list 
create a new list (test) that loops through numberList, and removes the first empty index in the numberList 
append the test list (essentiall the modifided numberlist) to the name list (make sure to cast it to an int)
append the namelist (namelist now contains the name, and the list of numbers) to total list 
reset nameList and numberList so when the file grabs a new line, it has a clear name/number list
close file
return totalList 
'''
def parse_ratings(file_name):
	fr = open(file_name)
	myList = []
	nameList = []
	numberList = []
	totalList = []
	for line in fr:
		myList = line.split(',')
		nameList.append(myList[0])
		numberList = myList[1].split(' ')
		test = []
		for i in numberList:
			if(i != ''):
				test.append(int(i))
		nameList.append(test)
		totalList.append(nameList)
		nameList = []
		numberList = []
	fr.close()
	return totalList

		
		
def main():
	#part 1a
	birth_rate = 8
	death_rate = 12
	new_immigrants_rate = 33
	List_of_rates = [birth_rate, death_rate, new_immigrants_rate]
	current_population = 1000000
	print compute_census(List_of_rates, current_population)
			
	#part 1b
	convert_seconds()
			
	#part 2
	str1 = 'I went skiing to '
	prompt1 = 'Enter a location: '
	str2 = ' it was really crowded and I stayed in line for '
	prompt2 = 'Enter number of hours: '
	str3 = ' hours'
	list_to_story = [str1, prompt1, str2, prompt2, str3]
	print(generate_story(list_to_story))
			
	#part 3a
	seq1 = 'CCGCCGCCGA'
	seq2 = 'CCTCCTCCTA'
	x = similarity_score(seq1, seq2)
	print(x)
			
	#part 3b
	genome = 'AAABBAABAAABBBAAABA'
	seq = 'AAA'
	x = best_match(genome, seq)
	print(x)
			
	#part 4
	list_of_numbers = [1, 2.5, 3, 8, 10.5, 5]
	x = calc_stats(list_of_numbers)
	print(x)
	
	#part 5
	x = parse_ratings("text.txt")
	print(x)

if __name__ == '__main__':
	main()



		
		
		
		
	
		
	
			
	
	

			
				
		
	
		
