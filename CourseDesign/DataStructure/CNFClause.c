//
//  CNFClause.c
//  CourseDesign
//
//  Created by 张储祺 on 2019/2/18.
//  Copyright © 2019 icegrave0391. All rights reserved.
//

#include "CNFClause.h"
#include <string.h>
clause createClause(int literalNum, int * literals){
    clause cls = (clause)malloc(sizeof(Clause)) ;
    cls -> literalCount = literalNum ;
    cls -> literals = (int *)malloc(sizeof(int) * literalNum) ;
    memcpy(cls -> literals, literals, literalNum * sizeof(int)) ;
    return cls ;
}

clause deepCpyClause(clause aclause){
    int literalNum = aclause -> literalCount ;
    int * literals = (int *)malloc(sizeof(int) * literalNum) ;
    memcpy(literals, aclause -> literals, literalNum * sizeof(int)) ;
    clause cls = createClause(literalNum, literals) ;
    return cls ;
}

//unit clause : 1.statusStill 2.literals contains only 1 elem not 0
int isUnitClause (Clause cls){
//    if(cls.clauseStatus == ClauseStatusDeleted)return 0 ;
//    else{
//        int flag = 0 ;
//        for(int i = 0 ; i < cls.literalCount ; i++){
//            if(cls.literals[i]) flag++ ;
//        }
//        if (flag == 1)return 1 ;
//        return 0;
//    }
    int flag = 0 ;
    for(int i = 0 ; i < cls.literalCount ; i++){
        if(cls.literals[i]) flag++ ;
    }
    if (flag == 1)return 1 ;
    return 0;
}

int isEmptyClause(Clause cls){
    for (int i = 0 ; i < cls.literalCount ; i++) {
        if(cls.literals[i])return 0 ;
    }
    return 1 ;
}

LiteralContainStatus literalStatusWithClause(Clause Cls, int literal){
    int iter = 0 ;
    int flag = 0 ;
    while (iter < Cls.literalCount) {
        if(!flag){
            if(Cls.literals[iter] == literal && !flag)flag = 1 ;  //contain
            else if(Cls.literals[iter] == - literal && !flag)flag = 2 ;  //contain inverse
        }
        else if(flag == 1){
            if(Cls.literals[iter] ==  - literal)return LiteralContainStatusContainBoth ;
        }
        else{
            if(Cls.literals[iter] == literal)return LiteralContainStatusContainBoth ;
        }
        iter ++ ;
    }
    switch (flag) {
        case 0:
            return LiteralContainStatusNotContain ;
            break;
        case 1:
            return LiteralContainStatusContain ;
            break ;
        case 2:
            return LiteralContainStatusContainInverse ;
            break ;
        default:
            break;
    }
    return 0 ;
}

void deleteLiteral(clause cls, int literal){
    for(int i = 0 ; i < cls -> literalCount ; i++){
        if(cls -> literals[i] == literal)cls -> literals[i] = 0 ;
    }
}

int findRandomLiteral(clause cls){
//    if(cls -> clauseStatus == ClauseStatusDeleted || isEmptyClause( *cls)) return 0 ;
//    if(
    for (int i = 0 ; i < cls -> literalCount; i++) {
        if(cls -> literals[i]) return cls -> literals[i] ;
    }
    return 0 ;
}

void recoverLiteral(clause cls, int literal){
    for (int i = 0 ; i < cls -> literalCount ; i++) {
        if(!cls -> literals[i]) cls -> literals[i] = 0 ;
    }
}

int findFirstLiteral(clause cls){
    for (int i = 0 ; i < cls -> literalCount ; i++) {
        if (cls -> literals[i]) {
            return cls -> literals[i] ;
        }
    }
    return  0 ;
}
