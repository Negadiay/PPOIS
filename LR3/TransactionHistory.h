#pragma once

#include <vector>
#include "Transaction.h"

class TransactionHistory {
private:
    std::vector<Transaction*> transactions;

public:
    void addTransaction(Transaction* transaction);
    void printHistory() const;
    const std::vector<Transaction*>& getTransactions() const;
};
