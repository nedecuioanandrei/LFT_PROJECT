x: int = 12;

contenxt
    map<var_name, Int()>
    declare()



int_declaration_node()
    var_name: string 
    imd_value: int

    run():
        contenxt.declare("int", var_name, imd_value)




x: int = 12; -> 0 INT_DECLARATION "x" 12
func add(a: int, b: int) -> int {
    x: int = 12;
    return x + b;
} ->
    1 PARAMAS "a" int "b" int -> Params(Node)
    7 VAR "a"
    8 VAR "b"
    2 SUM 7 8
    3 RETURN 2
    5 FUNCION_DECLATATION int 1 3


for (i: int = 0; i <= 12; ++i) {
    y: int = "Ana are mere"; 
}
    
    

    (ID, TYPE, ARGS)

    id| CONST_INT           |   value 
    id| CONST_FLOAT         |   value 
    id| COSNT_STR           |   value
    id| CONST_BOOL          |   value

    id| GET_{INT,FLOAT,STR,BOOL}             |   var_tag

    id| SUM                 |   id1, id2
    id| SUB                 |   id1, id2
    id| MUL                 |   id1, id2
    id| DIV                 |   id1, id2
    id| MOD                 |   id1, id2
    id| OR|AND              |   id1, id2
    id| NOT                 |   id    

    id| LT                  |   id1, id1
    id| GT                  |   id1, id1
    id| EQ                  |   id1, id1
    id| GE                  |   id1, id1
    id| LE                  |   id1, id1
    id| NE                  |   id1, id1

    id| SET_{INT, FLOAT, STR, BOOL}               |   var_tag, id
    id| IF                  | con_id true_block_id false_block_id

    global_context
    id| CALL_FUNC           | id1 next [parms]
        local_context

    print("ceva")
    sum(f(x), f(x))

    12 CONST 2
    13 LOAD "x" 12
    2 VAR "x"
    3 VAR "b"
    4 SUM 2 3
    5 RETURN 4
    