```
        Editor* editor = GetSubsystem<Editor>();
        if (!editor){
            editor = new Editor(context_);
            editor->InitEditor();
            context_->RegisterSubsystem(editor);
        }
```
