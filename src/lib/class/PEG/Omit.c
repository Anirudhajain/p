#include <lib/class/PEG/Omit.h>


Optr layout_PEG_Omit_Class_class;
Optr slot_PEG_Omit_parser;
Optr layout_PEG_Omit;


static void init_SMB_omit() {
    Symbol SMB_omit = new_Symbol(L"omit");
    Array PThreadedCode19379 = instantiate_Array_with(ThreadedCode_Class, 0, 1, (Optr)&t_method_return_self);
    Method PMethod19378 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode19379, 1, self);
    
    MethodClosure MC_SMB_omit = new_MethodClosure((Method)PMethod19378, PEG_Omit_Class);
    store_method(PEG_Omit_Class, SMB_omit, MC_SMB_omit);
}


static void init_SMB_not() {
    Symbol SMB_not = new_Symbol(L"not");
    // not. 
    Send PSend19382 = new_Send((Optr)slot_PEG_Omit_parser, SMB_not, 0);
    Array PThreadedCode19381 = instantiate_Array_with(ThreadedCode_Class, 0, 5, (Optr)&t_push_slot, (Optr)slot_PEG_Omit_parser, (Optr)&t_send0, (Optr)PSend19382, (Optr)&t_method_return);
    Method PMethod19380 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode19381, 1, PSend19382);
    
    MethodClosure MC_SMB_not = new_MethodClosure((Method)PMethod19380, PEG_Omit_Class);
    store_method(PEG_Omit_Class, SMB_not, MC_SMB_not);
}


static void init_SMB_withoutOmit() {
    Symbol SMB_withoutOmit = new_Symbol(L"withoutOmit");
    Array PThreadedCode19384 = instantiate_Array_with(ThreadedCode_Class, 0, 3, (Optr)&t_push_slot, (Optr)slot_PEG_Omit_parser, (Optr)&t_method_return);
    Method PMethod19383 = new_Method_with(empty_Array, empty_Array, empty_Array, PThreadedCode19384, 1, slot_PEG_Omit_parser);
    
    MethodClosure MC_SMB_withoutOmit = new_MethodClosure((Method)PMethod19383, PEG_Omit_Class);
    store_method(PEG_Omit_Class, SMB_withoutOmit, MC_SMB_withoutOmit);
}


static void init_SMB_parseOn_() {
    Symbol SMB_parseOn_ = new_Symbol(L"parseOn:");
    Variable VAR_input_0_0 = new_Variable_named(L"input", 0);
    Array PArray19386 = new_Array_with(1, (Optr)VAR_input_0_0);
    Symbol SMB_omitMatch_ = new_Symbol(L"omitMatch:");
    // omitMatch:. 
    Send PSend19388 = new_Send((Optr)slot_PEG_Omit_parser, SMB_omitMatch_, 1, (Optr)VAR_input_0_0);
    Array PThreadedCode19387 = instantiate_Array_with(ThreadedCode_Class, 0, 7, (Optr)&t_push_slot, (Optr)slot_PEG_Omit_parser, (Optr)&t_push_variable, (Optr)VAR_input_0_0, (Optr)&t_send1, (Optr)PSend19388, (Optr)&t_method_return);
    Method PMethod19385 = new_Method_with(PArray19386, empty_Array, empty_Array, PThreadedCode19387, 1, PSend19388);
    
    MethodClosure MC_SMB_parseOn_ = new_MethodClosure((Method)PMethod19385, PEG_Omit_Class);
    store_method(PEG_Omit_Class, SMB_parseOn_, MC_SMB_parseOn_);
}


static void init_SMB_omitMatch_() {
    Symbol SMB_omitMatch_ = new_Symbol(L"omitMatch:");
    Variable VAR_input_0_0 = new_Variable_named(L"input", 0);
    Array PArray19390 = new_Array_with(1, (Optr)VAR_input_0_0);
    // omitMatch:. 
    Send PSend19392 = new_Send((Optr)slot_PEG_Omit_parser, SMB_omitMatch_, 1, (Optr)VAR_input_0_0);
    Array PThreadedCode19391 = instantiate_Array_with(ThreadedCode_Class, 0, 7, (Optr)&t_push_slot, (Optr)slot_PEG_Omit_parser, (Optr)&t_push_variable, (Optr)VAR_input_0_0, (Optr)&t_send1, (Optr)PSend19392, (Optr)&t_method_return);
    Method PMethod19389 = new_Method_with(PArray19390, empty_Array, empty_Array, PThreadedCode19391, 1, PSend19392);
    
    MethodClosure MC_SMB_omitMatch_ = new_MethodClosure((Method)PMethod19389, PEG_Omit_Class);
    store_method(PEG_Omit_Class, SMB_omitMatch_, MC_SMB_omitMatch_);
}


static void init_SMB_parser_() {
    Symbol SMB_parser_ = new_Symbol(L"parser:");
    Variable VAR_aParser_0_0 = new_Variable_named(L"aParser", 0);
    Array PArray19394 = new_Array_with(1, (Optr)VAR_aParser_0_0);
    Assign PAssign19396 = new_Assign((Optr)slot_PEG_Omit_parser, (Optr)VAR_aParser_0_0);
    Array PThreadedCode19395 = instantiate_Array_with(ThreadedCode_Class, 0, 7, (Optr)&t_push1, (Optr)PAssign19396, (Optr)&t_push_variable, (Optr)VAR_aParser_0_0, (Optr)&t_assign, (Optr)&t_zap, (Optr)&t_method_return_self);
    Method PMethod19393 = new_Method_with(PArray19394, empty_Array, empty_Array, PThreadedCode19395, 2, PAssign19396, self);
    
    MethodClosure MC_SMB_parser_ = new_MethodClosure((Method)PMethod19393, PEG_Omit_Class);
    store_method(PEG_Omit_Class, SMB_parser_, MC_SMB_parser_);
}


static void init_class_SMB_on_() {
    Symbol SMB_on_ = new_Symbol(L"on:");
    Variable VAR_parser_0_0 = new_Variable_named(L"parser", 0);
    Array PArray19398 = new_Array_with(1, (Optr)VAR_parser_0_0);
    Symbol SMB_new = new_Symbol(L"new");
    // new. 
    Send PSend19400 = new_Send((Optr)self, SMB_new, 0);
    Symbol SMB_parser_ = new_Symbol(L"parser:");
    // parser:. 
    Send PSend19401 = new_Send((Optr)PSend19400, SMB_parser_, 1, (Optr)VAR_parser_0_0);
    Array PThreadedCode19399 = instantiate_Array_with(ThreadedCode_Class, 0, 8, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend19400, (Optr)&t_push_variable, (Optr)VAR_parser_0_0, (Optr)&t_send1, (Optr)PSend19401, (Optr)&t_method_return);
    Method PMethod19397 = new_Method_with(PArray19398, empty_Array, empty_Array, PThreadedCode19399, 1, PSend19401);
    
    MethodClosure MC_SMB_on_ = new_MethodClosure((Method)PMethod19397, HEADER(PEG_Omit_Class));
    store_method(HEADER(PEG_Omit_Class), SMB_on_, MC_SMB_on_);
}

void init_PEG_PEGOmit_layout() {
    layout_PEG_Omit_Class_class = (Optr)create_layout_with_vars(ObjectLayout_Class, 5);
    ((Array)layout_PEG_Omit_Class_class)->values[0] = slot_Kernel_Object_Object_Class_class_layout; // layout 
    ((Array)layout_PEG_Omit_Class_class)->values[1] = slot_Kernel_Object_Object_Class_class_superclass; // superclass 
    ((Array)layout_PEG_Omit_Class_class)->values[2] = slot_Kernel_Object_Object_Class_class_methods; // methods 
    ((Array)layout_PEG_Omit_Class_class)->values[3] = slot_Kernel_Object_Object_Class_class_name; // name 
    ((Array)layout_PEG_Omit_Class_class)->values[4] = slot_Kernel_Object_Object_Class_class_package; // package 
    
    Symbol  SMB_Omit = new_Symbol(L"Omit");
    slot_PEG_Omit_parser = (Optr)new_Slot(0, L"parser");
    layout_PEG_Omit = (Optr)create_layout_with_vars(ObjectLayout_Class, 1);
    ((Array)layout_PEG_Omit)->values[0] = slot_PEG_Omit_parser; // parser 
    PEG_Omit_Class = (Class)new_Class(PEG_Expression_Class, layout_PEG_Omit_Class_class);
    PEG_Omit_Class->layout = layout_PEG_Omit;
    PEG_Omit_Class->name = SMB_Omit;
    
}

void init_PEG_PEGOmit_methods() {
    init_SMB_omit();
    init_SMB_not();
    init_SMB_withoutOmit();
    init_SMB_parseOn_();
    init_SMB_omitMatch_();
    init_SMB_parser_();
    init_class_SMB_on_();
    
}