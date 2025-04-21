%summer olmstead , used https://swish.swi-prolog.org/
%Create a Prolog program that models family relationships, including direct (parents, siblings)
%and extended (cousins, aunts/uncles, ancestors) members, using facts and rules. Implement
%logical queries to deduce new relationships. Your code will be evaluated based on its size and the
%complexity of the rules, fact, etc. Create a family with 15 members or more with different
%relationships between them (mother, sibling, cousin, etc.).
%Part 1: Define Basic Family Facts - Use facts to define:
%• male(Name), female(Name)
%• parent(Parent, Child)
%• spouse(Person1, Person2)

%Part 1- family facts just defining people first 
male(deane).
male(dylan).
male(avery).
male(jeff).
male(tim).
male(owen).
male(grady).
male(grandpa).

female(summer).
female(gina).
female(minh).
female(milan).
female(katie).
female(allie).
female(leah).
female(pk).
female(judy).

%spouse relationships!
spouse(katie, tim).
spouse(tim, katie).
spouse(gina, jeff).
spouse(jeff, gina).
spouse(deane, minh).
spouse(minh, deane).


%parent relationships for each sub family 
parent(pk, gina).
parent(pk,deane).
parent(grandpa, gina).
parent(grandpa,deane).

parent(judy,tim).
parent(judy,jeff). 
parent(grady, tim).
parent(grady, jeff). 

parent(jeff, summer).
parent(gina, summer).
parent(jeff, avery).
parent(gina, avery).

parent(deane, milan).
parent(minh, milan).
parent(deane, dylan).
parent(minh, dylan).

parent(tim, leah).
parent(tim, allie).
parent(tim, owen).
parent(katie, leah).
parent(katie, allie).
parent(katie, owen).

%part 2 rules for relationships same as listed kinda in problem
father(F, C) :- parent(F, C), male(F).
mother(M, C) :- parent(M, C), female(M).

%based specifically if parents are same
sibling(A, B) :- parent(P, A), parent(P, B), A \= B.

%sibling and gender defined
brother(B, S) :- sibling(B, S), male(B).
sister(S, S2) :- sibling(S, S2), female(S).


grandparent(GP, C) :- parent(GP, P), parent(P, C).
grandchild(C, GP) :- grandparent(GP, C).

%difference of aunt and uncle is gender 
uncle(U, N) :- parent(P, N), sibling(U, P), male(U).
aunt(A, N) :- parent(P, N), sibling(A, P), female(A).

cousin(C1, C2) :-
    parent(P1, C1),
    parent(P2, C2),
    sibling(P1, P2),
    C1 \= C2.

%part 3 add recursive ancestor rule same as written
ancestor(A, D) :- parent(A, D).
ancestor(A, D) :- parent(A, X), ancestor(X, D).

%part 4 more tasks and querying when running 
married(X, Y) :- spouse(X, Y). %generally same thing
%after googling it seems related just means you have any common ancestor
related(X, Y) :- ancestor(A, X), ancestor(A, Y), X \= Y.

%how to count how many siblings someone has and return number 
num_siblings(Person, Count) :-
    findall(Sib, (sibling(Person, Sib)), Siblings),
    sort(Siblings, UniqueSiblings),
    length(UniqueSiblings, Count).

%step-relation examples..
step_grandparent(SGP, C) :- married(SGP, GP), grandparent(GP, C), SGP \= GP.
step_sibling(S1, S2) :- parent(P1, S1), parent(P2, S2), married(P1, P2), \+ parent(P1, S2), \+ parent(P2, S1), S1 \= S2.
