# BankAccount

 Simulates a bank with multiple accounts. 
 Interaction Explanation:
 
    Transaction type?: O
    Initial deposit?: amount
    Open an account, giving the initial deposit.
    Allowed if less than 100 accounts now open.
    Prints the new account number.
    
    Transaction type?: B
    Account number?: account_number
    A Balance inquiry, prints the account number 
    and the balance, only allowed if the account is open.
    
    Transaction type?: D
    Account number?: account_number 
    Amount?: amount	A Deposit, prints the account number 
    and new balance, only allowed if account open.
    
    Transaction type?: W
    Account number?: account_number 
    Amount?: amount	A Withdrawal, only allowed if account open 
    and sufficient funds available, prints 
    account number and new balance.
    
    Transaction type?: C
    Account number?: account_number	Close the account. Only allowed if account
    is open.
    
    Transaction type?: I
    Interest rate?: interest_rate	Compute interest at given % rate.
    and apply to all accounts
    
    Transaction type?: P	Print all the account numbers and amounts.
    
    Transaction type?: E	Close all accounts and exit program
    
    Transaction type?: S  Opens the bank
    
    Only the manager can do transactions S, P, I, and E with the PIN number 0909.
