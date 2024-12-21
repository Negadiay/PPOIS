#include "TransactionHistory.h"
#include <iostream>

void TransactionHistory::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

void TransactionHistory::printHistory() const {
    for (const auto& transaction : transactions) {
        std::cout << "Перевод в размере " << transaction->getAmount() << " на период " << transaction->getTimestamp() << std::endl;
    }
}

const std::vector<Transaction*>& TransactionHistory::getTransactions() const {
    return transactions;
}
