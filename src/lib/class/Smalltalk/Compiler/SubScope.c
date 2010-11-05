#include <lib/class/Smalltalk/Compiler/SubScope.h>


Optr layout_Smalltalk_Compiler_SubScope_Class_class;
Optr slot_Smalltalk_Compiler_SubScope_parentScope;
Optr layout_Smalltalk_Compiler_SubScope;


static void init_SMB_lookup_() {
    Symbol SMB_lookup_ = new_Symbol(L"lookup:");
    Variable VAR_anASTVariable_0_0 = new_Variable_named(L"anASTVariable", 0);
    Array PArray13337 = new_Array_with(1, (Optr)VAR_anASTVariable_0_0);
    Symbol SMB_name = new_Symbol(L"name");
    // name. 
    Send PSend13339 = new_Send((Optr)VAR_anASTVariable_0_0, SMB_name, 0);
    Symbol SMB_parentScope = new_Symbol(L"parentScope");
    // parentScope. 
    Send PSend13342 = new_Send((Optr)self, SMB_parentScope, 0);
    // lookup:. 
    Send PSend13343 = new_Send((Optr)PSend13342, SMB_lookup_, 1, (Optr)VAR_anASTVariable_0_0);
    Array PThreadedCode13341 = instantiate_Array_with(ThreadedCode_Class, 0, 8, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend13342, (Optr)&t_push_variable, (Optr)VAR_anASTVariable_0_0, (Optr)&t_send1, (Optr)PSend13343, (Optr)&t_block_return);
    Block PBlock13340 = new_Block_with(empty_Array, empty_Array, PThreadedCode13341, 1, PSend13343);
    Symbol SMB_at_ifAbsent_ = new_Symbol(L"at:ifAbsent:");
    // at:ifAbsent:. 
    Send PSend13344 = new_Send((Optr)slot_Smalltalk_Compiler_RootScope_declarations, SMB_at_ifAbsent_, 2, (Optr)PSend13339, (Optr)PBlock13340);
    Array PThreadedCode13338 = instantiate_Array_with(ThreadedCode_Class, 0, 11, (Optr)&t_push_slot, (Optr)slot_Smalltalk_Compiler_RootScope_declarations, (Optr)&t_push_variable, (Optr)VAR_anASTVariable_0_0, (Optr)&t_send0, (Optr)PSend13339, (Optr)&t_push_closure, (Optr)PBlock13340, (Optr)&t_send2, (Optr)PSend13344, (Optr)&t_method_return);
    Method PMethod13336 = new_Method_with(PArray13337, empty_Array, empty_Array, PThreadedCode13338, 1, PSend13344);
    
    MethodClosure MC_SMB_lookup_ = new_MethodClosure((Method)PMethod13336, Smalltalk_Compiler_SubScope_Class);
    store_method(Smalltalk_Compiler_SubScope_Class, SMB_lookup_, MC_SMB_lookup_);
}


static void init_SMB_parentScope() {
    Symbol SMB_parentScope = new_Symbol(L"parentScope");
    Array PThreadedCode13346 = instantiate_Array_with(ThreadedCode_Class, 0, 3, (Optr)&t_push_slot, (Optr)slot_Smalltalk_Compiler_SubScope_parentScope, (Optr)&t_method_return);
    Method PMethod13345 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode13346, 1, slot_Smalltalk_Compiler_SubScope_parentScope);
    
    MethodClosure MC_SMB_parentScope = new_MethodClosure((Method)PMethod13345, Smalltalk_Compiler_SubScope_Class);
    store_method(Smalltalk_Compiler_SubScope_Class, SMB_parentScope, MC_SMB_parentScope);
}


static void init_SMB_parentScope_() {
    Symbol SMB_parentScope_ = new_Symbol(L"parentScope:");
    Variable VAR_anObject_0_0 = new_Variable_named(L"anObject", 0);
    Array PArray13348 = new_Array_with(1, (Optr)VAR_anObject_0_0);
    Assign PAssign13350 = new_Assign((Optr)slot_Smalltalk_Compiler_SubScope_parentScope, (Optr)VAR_anObject_0_0);
    Array PThreadedCode13349 = instantiate_Array_with(ThreadedCode_Class, 0, 7, (Optr)&t_push1, (Optr)PAssign13350, (Optr)&t_push_variable, (Optr)VAR_anObject_0_0, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_method_return_self);
    Method PMethod13347 = new_Method_with(PArray13348, empty_Array, empty_Array, PThreadedCode13349, 2, PAssign13350, self);
    
    MethodClosure MC_SMB_parentScope_ = new_MethodClosure((Method)PMethod13347, Smalltalk_Compiler_SubScope_Class);
    store_method(Smalltalk_Compiler_SubScope_Class, SMB_parentScope_, MC_SMB_parentScope_);
}


static void init_SMB_depth() {
    Symbol SMB_depth = new_Symbol(L"depth");
    Symbol SMB_parentScope = new_Symbol(L"parentScope");
    // parentScope. 
    Send PSend13353 = new_Send((Optr)self, SMB_parentScope, 0);
    // depth. 
    Send PSend13354 = new_Send((Optr)PSend13353, SMB_depth, 0);
    Symbol SMB__plus_ = new_Symbol(L"+");
    SmallInt int_1 = new_SmallInt(1);
    Constant int_1_Const = new_Constant((Optr)int_1);
    // +. 
    Send PSend13355 = new_Send((Optr)PSend13354, SMB__plus_, 1, (Optr)int_1_Const);
    Array PThreadedCode13352 = instantiate_Array_with(ThreadedCode_Class, 0, 9, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend13353, (Optr)&t_send0, (Optr)PSend13354, (Optr)&t_push_1, (Optr)&t_send1, (Optr)PSend13355, (Optr)&t_method_return);
    Method PMethod13351 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode13352, 1, PSend13355);
    
    MethodClosure MC_SMB_depth = new_MethodClosure((Method)PMethod13351, Smalltalk_Compiler_SubScope_Class);
    store_method(Smalltalk_Compiler_SubScope_Class, SMB_depth, MC_SMB_depth);
}


static void init_class_SMB_new_() {
    Symbol SMB_new_ = new_Symbol(L"new:");
    Variable VAR_parentScope_0_0 = new_Variable_named(L"parentScope", 0);
    Array PArray13357 = new_Array_with(1, (Optr)VAR_parentScope_0_0);
    Symbol SMB_new = new_Symbol(L"new");
    // new. 
    Send PSend13359 = new_Send((Optr)self, SMB_new, 0);
    Symbol SMB_parentScope_ = new_Symbol(L"parentScope:");
    // parentScope:. 
    Send PSend13360 = new_Send((Optr)PSend13359, SMB_parentScope_, 1, (Optr)VAR_parentScope_0_0);
    Array PThreadedCode13358 = instantiate_Array_with(ThreadedCode_Class, 0, 8, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend13359, (Optr)&t_push_variable, (Optr)VAR_parentScope_0_0, (Optr)&t_send1, (Optr)PSend13360, (Optr)&t_method_return);
    Method PMethod13356 = new_Method_with(PArray13357, empty_Array, empty_Array, PThreadedCode13358, 1, PSend13360);
    
    MethodClosure MC_SMB_new_ = new_MethodClosure((Method)PMethod13356, HEADER(Smalltalk_Compiler_SubScope_Class));
    store_method(HEADER(Smalltalk_Compiler_SubScope_Class), SMB_new_, MC_SMB_new_);
}

void init_Smalltalk_Compiler_PSubScope_layout() {
    layout_Smalltalk_Compiler_SubScope_Class_class = (Optr)create_layout_with_vars(ObjectLayout_Class, 6);
    ((Array)layout_Smalltalk_Compiler_SubScope_Class_class)->values[0] = slot_Kernel_Object_Object_Class_class_layout; // layout 
    ((Array)layout_Smalltalk_Compiler_SubScope_Class_class)->values[1] = slot_Kernel_Object_Object_Class_class_superclass; // superclass 
    ((Array)layout_Smalltalk_Compiler_SubScope_Class_class)->values[2] = slot_Kernel_Object_Object_Class_class_methods; // methods 
    ((Array)layout_Smalltalk_Compiler_SubScope_Class_class)->values[3] = slot_Kernel_Object_Object_Class_class_name; // name 
    ((Array)layout_Smalltalk_Compiler_SubScope_Class_class)->values[4] = slot_Kernel_Object_Object_Class_class_package; // package 
    ((Array)layout_Smalltalk_Compiler_SubScope_Class_class)->values[5] = slot_Smalltalk_Compiler_RootScope_Class_class_decls; // decls 
    
    Symbol  SMB_SubScope = new_Symbol(L"SubScope");
    slot_Smalltalk_Compiler_SubScope_parentScope = (Optr)new_Slot(1, L"parentScope");
    layout_Smalltalk_Compiler_SubScope = (Optr)create_layout_with_vars(ObjectLayout_Class, 2);
    ((Array)layout_Smalltalk_Compiler_SubScope)->values[0] = slot_Smalltalk_Compiler_RootScope_declarations; // declarations 
    ((Array)layout_Smalltalk_Compiler_SubScope)->values[1] = slot_Smalltalk_Compiler_SubScope_parentScope; // parentScope 
    Smalltalk_Compiler_SubScope_Class = (Class)new_Class(Smalltalk_Compiler_RootScope_Class, layout_Smalltalk_Compiler_SubScope_Class_class);
    Smalltalk_Compiler_SubScope_Class->layout = layout_Smalltalk_Compiler_SubScope;
    Smalltalk_Compiler_SubScope_Class->name = SMB_SubScope;
    
}

void init_Smalltalk_Compiler_PSubScope_methods() {
    init_SMB_lookup_();
    init_SMB_parentScope();
    init_SMB_parentScope_();
    init_SMB_depth();
    init_class_SMB_new_();
    
}