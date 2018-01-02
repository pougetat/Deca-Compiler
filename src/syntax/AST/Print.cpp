#include "Print.h"

Print::Print(TokenType token_type)
{
    m_token_type = token_type;
}

void Print::Display(string tab)
{
    cout << tab << ">[PRINT]"<< endl;
    for (AbstractExpr * expr : *m_list_args)
    {
        expr->Display(tab + "--");
    }
}

void Print::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * return_type)
{
    for (AbstractExpr * expr : *m_list_args)
    {
        AbstractType * expr_type =
            expr->VerifyExpr(env_types, env_exp, class_name);

        if (!expr_type->IsFloatType() && !expr_type->IsIntType() 
            && !expr_type->IsStringType() && !expr_type->IsBooleanType())
        {
            throw runtime_error(
                "[PRINT : FLOAT, INT, STRING, BOOL OPERAND EXPECTED]"
            );
        }
    }
}

void Print::CodeGenInst(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    if (m_list_args->size() == 0)
    {
        gen_env->output_file
            << "    ; push java.lang.System.out (type PrintStream)"
            << endl;
        gen_env->output_file 
            << "    getstatic "
            << "java/lang/System/out Ljava/io/PrintStream;"
            << endl;
        gen_env->output_file << "    ldc \" \"" << endl;
        gen_env->output_file 
            << "    invokevirtual "
            << "java/io/PrintStream/println(Ljava/lang/String;)V"
            << endl;
    }
    else
    {
        for (AbstractExpr * print_arg : *m_list_args)
        {
            gen_env->output_file
                << "    ; push java.lang.System.out (type PrintStream)"
                << endl;
            gen_env->output_file 
                << "    getstatic "
                << "java/lang/System/out Ljava/io/PrintStream;"
                << endl;

            print_arg->CodeGenExpr(env_types, gen_env);

            gen_env->output_file << "    ; invoke println" << endl;
            if (print_arg->m_expr_type->IsIntType())
            {
                gen_env->output_file
                    << "    invokevirtual "
                    << "java/io/PrintStream/println(I)V"
                    << endl;
            }
            if (print_arg->m_expr_type->IsStringType())
            {
                gen_env->output_file
                    << "    invokevirtual "
                    << "java/io/PrintStream/println(Ljava/lang/String;)V" 
                    << endl;  
            }
            if (print_arg->m_expr_type->IsBooleanType())
            {
                gen_env->output_file
                    << "    invokevirtual "
                    << "java/io/PrintStream/println(Z)V" 
                    << endl;  
            }
        }
    }
}