def solution(phone_book):
    phone_book.sort()

    for i in range(len(phone_book)-1):
        size = len(phone_book[i])
        if(phone_book[i] == phone_book[i + 1][:size]):
            return False
    return True
