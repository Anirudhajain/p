#include <lib/class/Testing/TestCase.h>


Optr layout_Testing_TestCase_Class_class;
Optr slot_Testing_TestCase_testSelector;
Optr layout_Testing_TestCase;


static void init_SMB_testSelector_() {
    Symbol SMB_testSelector_ = new_Symbol(L"testSelector:");
    Variable VAR_anObject_0_0 = new_Variable_named(L"anObject", 0);
    Array PArray12065 = new_Array_with(1, (Optr)VAR_anObject_0_0);
    Assign PAssign12067 = new_Assign((Optr)slot_Testing_TestCase_testSelector, (Optr)VAR_anObject_0_0);
    Array PThreadedCode12066 = instantiate_Array_with(ThreadedCode_Class, 0, 7, (Optr)&t_push1, (Optr)PAssign12067, (Optr)&t_push_variable, (Optr)VAR_anObject_0_0, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_method_return_self);
    Method PMethod12064 = new_Method_with(PArray12065, empty_Array, empty_Array, PThreadedCode12066, 2, PAssign12067, self);
    
    MethodClosure MC_SMB_testSelector_ = new_MethodClosure((Method)PMethod12064, Testing_TestCase_Class);
    store_method(Testing_TestCase_Class, SMB_testSelector_, MC_SMB_testSelector_);
}


static void init_SMB_testSelector() {
    Symbol SMB_testSelector = new_Symbol(L"testSelector");
    Array PThreadedCode12069 = instantiate_Array_with(ThreadedCode_Class, 0, 3, (Optr)&t_push_slot, (Optr)slot_Testing_TestCase_testSelector, (Optr)&t_method_return);
    Method PMethod12068 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode12069, 1, slot_Testing_TestCase_testSelector);
    
    MethodClosure MC_SMB_testSelector = new_MethodClosure((Method)PMethod12068, Testing_TestCase_Class);
    store_method(Testing_TestCase_Class, SMB_testSelector, MC_SMB_testSelector);
}


static void init_class_SMB_run() {
    Symbol SMB_run = new_Symbol(L"run");
    Symbol SMB_new = new_Symbol(L"new");
    // new. 
    Send PSend12072 = new_Send((Optr)self, SMB_new, 0);
    // run. 
    Send PSend12073 = new_Send((Optr)PSend12072, SMB_run, 0);
    Array PThreadedCode12071 = instantiate_Array_with(ThreadedCode_Class, 0, 6, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend12072, (Optr)&t_send0, (Optr)PSend12073, (Optr)&t_method_return);
    Method PMethod12070 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode12071, 1, PSend12073);
    
    MethodClosure MC_SMB_run = new_MethodClosure((Method)PMethod12070, HEADER(Testing_TestCase_Class));
    store_method(HEADER(Testing_TestCase_Class), SMB_run, MC_SMB_run);
}

void init_Testing_PTestCase_layout() {
    layout_Testing_TestCase_Class_class = (Optr)create_layout_with_vars(ObjectLayout_Class, 5);
    ((Array)layout_Testing_TestCase_Class_class)->values[0] = slot_Kernel_Object_Object_Class_class_layout; // layout 
    ((Array)layout_Testing_TestCase_Class_class)->values[1] = slot_Kernel_Object_Object_Class_class_superclass; // superclass 
    ((Array)layout_Testing_TestCase_Class_class)->values[2] = slot_Kernel_Object_Object_Class_class_methods; // methods 
    ((Array)layout_Testing_TestCase_Class_class)->values[3] = slot_Kernel_Object_Object_Class_class_name; // name 
    ((Array)layout_Testing_TestCase_Class_class)->values[4] = slot_Kernel_Object_Object_Class_class_package; // package 
    
    Symbol  SMB_TestCase = new_Symbol(L"TestCase");
    slot_Testing_TestCase_testSelector = (Optr)new_Slot(0, L"testSelector");
    layout_Testing_TestCase = (Optr)create_layout_with_vars(ObjectLayout_Class, 1);
    ((Array)layout_Testing_TestCase)->values[0] = slot_Testing_TestCase_testSelector; // testSelector 
    Testing_TestCase_Class = (Class)new_Class(Object_Class, layout_Testing_TestCase_Class_class);
    Testing_TestCase_Class->layout = layout_Testing_TestCase;
    Testing_TestCase_Class->name = SMB_TestCase;
    
}

void init_Testing_PTestCase_methods() {
    init_SMB_testSelector_();
    init_SMB_testSelector();
    init_class_SMB_run();
    
}