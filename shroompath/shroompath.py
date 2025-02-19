#
#  shroompath.py
#  shroompath
#
#  Created by Dimitris Chatzigeorgiou on 16/2/25.
#


def generate_combinations(n, current = "", result = []):

    if len(current) == n:
        print(current)
        result.extend(current)
        return result
    
    for character in "ab":
        generate_combinations(n=n, current=current+character, result=result)

    return result

if __name__ == "__main__":
    lst = generate_combinations(n=1)
    print(lst)

    s = 10
    x = 2
    y = 5

    # Adding the initial value to combo (combo contains the current sum of the shrooms in the basket)
    current = lst[0]
    if current == 'a':
        combo = x
    else:
        combo = y

    # Contains the current length of the a and b strings
    current_length = 1
    # Contains the number of a and b in the list
    count = (2 ** current_length) * current_length
    
    i = 0
    # Counter variable to keep track of how many steps Takis has done
    steps = 1
    while combo < s:
        # When i reaches the number of total mushrooms create combinations with one more letter, add them to the main list
        # and increases the count variable
        if i == count:
            lst = generate_combinations(n=current_length+1) # Generating new combintaions with one more extra character
                                                            # and overwriting the previous combinations with the new one
            current_length += 1 # Increasing the current length of the strings
            count = (2 ** current_length) * current_length # Increasing the total number of combinations
            i = 0 # Reseting the position
            steps = 0

        # Checking if the current shroom is the same as the ones in the basket
        if lst[i] == current:   # If the shroom is the same then the correct value is added to the combo
            # Adding the correct value based on the type of mushrooms already in the basket (a or b)
            if current == 'a':
                combo += x
            else:
                combo += y
        else:   # Else the shrooms are thrown out and the current is picked up (combo is reset and the value of the current shroom
                #                                                               is added to the combo)
            # Changing the type of shrooms in the basket to the current one
            current = lst[i]
            # Reseting the combo with the correct value based on the type of mushrooms already in the basket (a or b)
            if current == 'a':
                combo = x
            else:
                combo = y

        i += 1
        steps += 1
    
    moddddd = 10**9 + 7
    print(steps % moddddd)
