#ifndef DOCTOR_H
#define DOCTOR_H

namespace Diagnose {
    void validateSchemaAndTables();
}

namespace Validator {
    void validateSchema();
    void validateUserTable();
    void validateGeographyTable();
    void validateComputerScienceTable();
    void validateHistoryTable();
    void validateQuestionsSetTable();
    void validateResultTable();
}

namespace Fixer {
    void fixSchema();
    void fixUserTable();
    void fixGeographyTable();
    void fixComputerScienceTable();
    void fixHistoryTable();
    void fixQuestionsSetTable();
    void fixResultTable();
}

#endif // DOCTOR_H
