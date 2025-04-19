#!/bin/bash

# Попытка загрузить артефакты с помощью actions/upload-artifact@v3
# Убедитесь, что $GITHUB_PATH установлено правильно

echo "Загрузка артефактов..."

uses: actions/upload-artifact@v3
      with:
        name: artifacts
        path: artifacts
