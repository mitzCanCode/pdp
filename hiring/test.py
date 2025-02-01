def parallel_sort(lst, lst_n):
    do_sort = True
    while do_sort:
        # Sorting part 
        do_sort = False
        for i in range(len(lst)-1):
                if lst[i] < lst[i+1]:
                        do_sort = True
                        lst[i], lst[i+1] = lst[i+1], lst[i]
                        lst_n[i], lst_n[i+1] = lst_n[i+1], lst_n[i]
    for i in range(len(lst)-1):
        print(f"{lst_n[i]}: {lst[i]}")
    return lst, lst_n


def main():
    candidates = 5
    total_bronze = 3
    total_silver = 1
    total_gold = 1
    total_all = total_gold + total_silver + total_bronze

    total_given = 0
    gold_given = 0
    silver_given = 0
    bronze_given = 0

    gold = [8, 2, 12, 7, 9]
    silver = [6, 1, 9, 5, 9]
    bronze = [3, 1 , 4, 3, 9]

    gold_n = [0, 1, 2, 3, 4]
    silver_n = [0, 1, 2, 3, 4]
    bronze_n = [0, 1, 2, 3, 4]

    used = []
    S = 0

    gold, gold_n = parallel_sort(gold, gold_n)
    i = 0
    while gold_given < total_gold and i < candidates:
        if gold_n[i] in used:
            i += 1
            continue
        # Checking if the performance of bronze for the same candidate is the same or better 
        if (bronze[gold_n[i]] >= gold[i]) and (bronze_given < total_bronze) :
            S += bronze[gold_n[i]]
            bronze_given += 1
        # Checking if the performance of silver for the same candidate is the same or better 
        elif (silver[gold_n[i]] >= gold[i]) and (silver_given < total_silver):
            S += silver[gold_n[i]]
            silver_given += 1
        elif (gold_given < total_gold):
            S += gold[i]
            gold_given += 1
        else:
            break
        used.append(gold_n[i])
        i += 1

    silver, silver_n = parallel_sort(silver, silver_n)
    i = 0
    while silver_given < total_silver and i < candidates:
        if silver_n[i] in used:
            i += 1
            continue
        # Checking if the performance of bronze for the same candidate is the same or better 
        if (bronze[silver_n[i]] >= silver[i]) and (bronze_given < total_bronze):
            S += bronze[silver_n[i]]
            bronze_given += 1
        elif (silver_given < total_silver):
            S += silver[i]
            silver_given += 1
        else:
            break
        used.append(silver_n[i])
        i += 1

    bronze, bronze_n = parallel_sort(bronze, bronze_n)
    i = 0
    print(len(bronze_n)-1)
    while bronze_given < total_bronze and i < candidates:
        if bronze_n[i] in used:
            i += 1
            continue
        if (bronze_given < total_bronze):
            S += bronze[i]
            bronze_given += 1
        else:
            break
        used.append(bronze_n[i])
        i += 1
    print(f"Sum: {S}\nBronze given: {bronze_given}\nSilver given: {silver_given}\nGold given: {gold_given}")


if __name__ == "__main__":
    main()




    # candidates = int(input("Total candidates: "))

    # total_bronze = int(input("Total bronze to give: "))

    # total_silver = int(input("Total silver to give: "))

    # total_gold = int(input("Total gold to give: "))

    # total_all = total_gold + total_silver + total_bronze


    # for i in range(candidates):

    #       print(f"Candidate {i}")

    #       bronze_temp = int(input("Bronze: "))

    #       silver_temp = int(input("Silver: "))

    #       gold_temp = int(input("Gold: "))

    #       gold.append(gold_temp)

    #       silver.append(silver_temp)

    #       bronze.append(bronze_temp)

    #       gold_n.append(i)

    #       silver_n.append(i)

    #       bronze_n.append(i)


#    if (total_gold > 0):

#          S, used, gold_given = find_fnc(main = gold, main_n = gold_n, next=silver, used=used, S=S, total=total_gold)

#          total_all += gold_given


#    if (total_silver > 0) and (total_given < total_all):

#          S, used, silver_given = find_fnc(main = silver, main_n = silver_n, next=bronze, used=used, S=S, total=total_silver)

#          total_all += silver_given


#    if (total_bronze > 0) and (total_given < total_all):

#          do_sort = True

#          while do_sort:

#                # Sorting part 

#                do_sort = False

#                for i in range(len(bronze)-1):

#                      if bronze[i] < bronze[i+1]:

#                            do_sort = True

#                            bronze[i], bronze[i+1] = bronze[i+1], bronze[i]

#                            bronze_n[i], bronze_n[i+1] = bronze_n[i+1], bronze_n[i]

#          i = 0

#          while total_given < total_all and (bronze_given < total_bronze):

#                if i not in used:

#                      total_given += 1

#                      S += bronze[i]

#                      used.append(i)

#                      bronze_given += 1