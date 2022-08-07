
#include <iostream>

#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

    void LinearProgrammingExample()
    {
        std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("SCIP"));
        if(!solver)
        {
            std::cout << "SCIP solver unavailable." << std::endl;
            return;
        }


        // define variables

        // x and y are between 0 and 10
        MPVariable* const x = solver->MakeNumVar(0.0, 10.0, "x");
        MPVariable* const y = solver->MakeNumVar(0.0, 10.0, "y");
        std::cout << "Number of variables = " << solver->NumVariables() << std::endl;

        // constraints
        // 1*y < 2
        MPConstraint* const c0 = solver->MakeRowConstraint(-(solver->infinity()), 2.0);
        c0->SetCoefficient(x, 0);
        c0->SetCoefficient(y, 1);

        // 1*x < 3
        MPConstraint* const c1 = solver->MakeRowConstraint(-(solver->infinity()), 3.0);
        c1->SetCoefficient(x, 1);
        c1->SetCoefficient(y, 0);

        // Objective function: maximize x + y
        MPObjective* const objective = solver->MutableObjective();
        objective->SetCoefficient(x, 1);
        objective->SetCoefficient(y, 1);
        objective->SetMaximization();

        const MPSolver::ResultStatus result_status = solver->Solve();

        if (result_status != MPSolver::OPTIMAL)
        {
            std::cout << "The problem does not have an optimal solution!" << std::endl;
        }

        LOG(INFO) << "Solution:";
        LOG(INFO) << "Optimal objective value = " << objective->Value();
        LOG(INFO) << x->name() << " = " << x->solution_value();
        LOG(INFO) << y->name() << " = " << y->solution_value();
    }
}

int main(int /*argc*/, char** /*argv*/)
{
    operations_research::LinearProgrammingExample();
    return EXIT_SUCCESS;
}

